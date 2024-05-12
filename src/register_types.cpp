#include "register_types.h"
#include "gdsha512.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gd_sha512_module(godot::ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<GDSha512>();
}

void uninitialize_gd_sha512_module(godot::ModuleInitializationLevel p_level) {
    // No cleanup needed for this module
}

extern "C" {

// Initialization function.
GDExtensionBool GDE_EXPORT gd_sha512_library_init(const GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
  
  init_obj.register_initializer(initialize_gd_sha512_module);
  init_obj.register_terminator(uninitialize_gd_sha512_module);
  init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}

}




// #include "register_types.h"
// #include "gdsha512.h"

// #include <gdextension/gdextension.h>

// using namespace godot;

// void initialize_sha512_extension(ModuleInitializationLevel p_level) {
//     if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
//         ClassDB::register_class<GDSha512>();
//     }
// }

// void uninitialize_sha512_extension(ModuleInitializationLevel p_level) {
//     if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
//         // No need to unregister classes in GDExtension
//     }
// }

// extern "C" {

// // Initialization.
// GD_EXTENSION_INIT(sha512_extension_init, sha512_extension_term) {
//     GDExtensionBinding::InitObject init_obj(sha512_extension_init, sha512_extension_term);
//     init_obj.register_initializer(initialize_sha512_extension);
//     init_obj.register_terminator(uninitialize_sha512_extension);
//     init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
// }

// }

