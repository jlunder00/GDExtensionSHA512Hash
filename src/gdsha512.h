#ifndef GDSHA512_H
#define GDSHA512_H

#include <godot.hpp>
#include <ref.hpp>

namespace godot {

class GDSha512 : public Reference {
    GDCLASS(GDSha512, Reference);

protected:
    static void _bind_methods();

public:
    GDSha512();
    ~GDSha512();

    String hash(String input);
};

}

#endif // GDSHA512_H

