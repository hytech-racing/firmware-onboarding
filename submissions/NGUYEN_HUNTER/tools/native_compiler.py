Import("env")
import importlib.util
import os
import shutil
from pathlib import Path

# Native's builder selects GCC immediately before BuildProgram. Override at
# that boundary so test/library environments inherit the selected compiler.
if not shutil.which("g++"):
    spec = importlib.util.find_spec("ziglang")
    if spec is None:
        raise RuntimeError("Native tests need g++ or: python -m pip install ziglang==0.15.2")
    executable = str(Path(spec.origin).parent / ("zig.exe" if os.name == "nt" else "zig"))
    original_build_program = env.BuildProgram
    def build_with_zig(environment, *args, **kwargs):
        environment.Replace(CC=[executable, "cc"], CXX=[executable, "c++"], LINK=[executable, "c++"], AR=[executable, "ar"], RANLIB=[executable, "ranlib"])
        return original_build_program(*args, **kwargs)
    env.AddMethod(build_with_zig, "BuildProgram")
