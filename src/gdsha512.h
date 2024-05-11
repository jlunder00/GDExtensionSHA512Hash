#ifndef GDSHA512_H
#define GDSHA512_H

#include <godot_cpp/classes/ref.hpp>
// #include <godot_cpp/core/string.hpp>

using namespace godot;

class GDSha512 : public RefCounted {
    GDCLASS(GDSha512, RefCounted);

protected:
    static void _bind_methods();

public:
    GDSha512();
    virtual ~GDSha512();

    String hash(const String &input);
};

#endif // GDSHA512_H
