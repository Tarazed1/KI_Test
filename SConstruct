#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For the reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

def add_sources(sources, dir, extension):
    for f in os.listdir(dir):
        if f.endswith("." + extension):
            sources.append(dir + "/" + f)

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["extension/src/"])
env.Append(CPPPATH=["extension/src/Movement/"])
env.Append(CPPPATH=["extension/src/Utility/"])
#env.Append(LIBPATH=['/out/build/x64-Debug/Framework'])
#env.Append(LIBS=['Framework'])
sources = Glob("extension/src/*.cpp")
add_sources(sources, "extension/src/Movement", "cpp")
add_sources(sources, "extension/src/Utility", "cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/bin/libgdsummator.{}.{}.framework/libgdsummator.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "game/bin/libgdsummator{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
