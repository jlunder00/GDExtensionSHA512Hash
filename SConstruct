#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

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
else:
    library = env.SharedLibrary(
        "demo/bin/libgdsha512{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)




# import os

# # Create a construction environment
# env = Environment()

# # Automatically set the correct suffix for shared libraries depending on the platform
# platform = ARGUMENTS.get('platform', 'linux')
# if platform == 'windows':
#     env['SHLIB_SUFFIX'] = '.dll'
# elif platform == 'osx':
#     env['SHLIB_SUFFIX'] = '.dylib'
# else:
#     env['SHLIB_SUFFIX'] = '.so'


# # # Assuming 'godot-cpp' is a sibling directory to your source directory
# # godot_cpp_path = '#godot-cpp'
# # include_path = os.path.join(godot_cpp_path, 'gen', 'include')
# # include_core_path = os.path.join(include_path, 'godot_cpp', 'core')
# # include_classes_path = os.path.join(include_path, 'godot_cpp', 'classes')
# # include_gdextension_path = os.path.join(godot_cpp_path, 'gdextension')

# # # Append all relevant paths to the include path
# # env.Append(CPPPATH=[include_path, include_core_path, include_classes_path, include_gdextension_path])

# # # Assuming the static library is in 'godot-cpp/bin'
# # env.Append(LIBPATH=[os.path.join(godot_cpp_path, 'bin')])
# # Set paths to the godot-cpp library
# env.Append(CPPPATH=[
#     'godot-cpp/gen/include',  # General include directory
#     'godot-cpp/gen/include/godot_cpp',  # Additional includes for godot_cpp specifics
#     'godot-cpp/gen/include/godot_cpp/classes',  # Class definitions
#     'godot-cpp/gen/include/godot_cpp/core',  # Core functionality
#     'godot-cpp/include',
#     'godot-cpp/include/godot_cpp',
#     'godot-cpp/include/godot_cpp/classes',
#     'godot-cpp/include/godot_cpp/core',
#     'godot-cpp/gdextension'
# ])

# env.Append(LIBPATH=['#godot-cpp/bin'])
# env.Append(LIBS=['godot-cpp.linux.template_debug.x86_64', 'crypto'])

# # Source files
# sources = ['src/gdsha512.cpp']

# # Build the shared library
# target_name = 'bin/libgdsha512' + env['SHLIB_SUFFIX']
# env.SharedLibrary(target=target_name, source=sources)
