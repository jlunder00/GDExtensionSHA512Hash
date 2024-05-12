#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# OpenSSL libraries
if env['platform'] == 'linux' or env['platform'] == 'macos':
    env.Append(LIBS=['ssl', 'crypto'])
elif env['platform'] == 'windows':
    # Define paths to your OpenSSL installation on Windows
    # Adjust the paths below to match where OpenSSL is installed on your system
    openssl_lib_path = 'C:/OpenSSL-Win64/lib'
    openssl_include_path = 'C:/OpenSSL-Win64/include'

    env.Append(LIBPATH=[openssl_lib_path])
    env.Append(CPPPATH=[openssl_include_path])
    env.Append(LIBS=['libssl', 'libcrypto'])  # The names might differ; check your installation

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdsha512.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "windows":
    # Windows might require .dll and .lib files to be explicitly named
    library = env.SharedLibrary(
        "demo/bin/libgdsha512.{}.{}".format(env["target"], env["SHLIBSUFFIX"]),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "demo/bin/libgdsha512{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)


