#include "register_types.h"
#include "gdsha512.h"

#include <gdextension/gdextension.h>

using namespace godot;

void initialize_sha512_extension(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        ClassDB::register_class<GDSha512>();
    }
}

void uninitialize_sha512_extension(ModuleInitializationLevel p_level) {
    if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
        // No need to unregister classes in GDExtension
    }
}

extern "C" {

// Initialization.
GD_EXTENSION_INIT(sha512_extension_init, sha512_extension_term) {
    GDExtensionBinding::InitObject init_obj(sha512_extension_init, sha512_extension_term);
    init_obj.register_initializer(initialize_sha512_extension);
    init_obj.register_terminator(uninitialize_sha512_extension);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
}

}

