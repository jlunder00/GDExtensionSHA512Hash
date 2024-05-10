import os

# Create a construction environment
env = Environment()

env = env.Clone()

# Automatically set the correct suffix for shared libraries depending on the platform
platform = ARGUMENTS.get('platform', 'linux')
if platform == 'windows':
    env['SHLIB_SUFFIX'] = '.dll'
elif platform == 'osx':
    env['SHLIB_SUFFIX'] = '.dylib'
else:
    env['SHLIB_SUFFIX'] = '.so'
# Setup paths for the Godot headers and sources
godot_cpp_path = 'godot-cpp'
include_path = os.path.join(godot_cpp_path, 'include', 'godot_cpp')  # Corrected to include 'godot_cpp'
include_core_path = os.path.join(include_path, 'core')
include_gen_path = os.path.join(include_path, 'gen')  # Not needed in your specific case but included for completeness
include_ref_path = os.path.join(include_path, 'classes')
include_extensions_path = os.path.join(godot_cpp_path, 'gdextension')
base_include = os.path.join(godot_cpp_path, 'include')

# Configure environment paths
env.Append(CPPPATH=[include_path, include_core_path, include_gen_path, include_extensions_path, include_ref_path, base_include])
env.Append(LIBPATH=[os.path.join(godot_cpp_path, 'bin')])
# env.Append(LIBS=['godot-cpp.linux.debug.64'])  # Modify this for your platform
env.Append(LIBS=['godot-cpp.linux.template_debug.x86_64'])  # Correctly referencing the debug library file

# Source files
src_files = ['src/gdsha512.cpp', 'src/register_types.cpp']

# Build the shared library
target_name = 'libgdsha512' + env['SHLIB_SUFFIX']
env.SharedLibrary(target=target_name, source=src_files)
