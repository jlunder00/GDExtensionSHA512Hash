#include "gdsha512.h"
#include <openssl/sha.h>

using namespace godot;

void GDSha512::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hash", "input"), &GDSha512::hash);
}

GDSha512::GDSha512() {
}

GDSha512::~GDSha512() {
}

String GDSha512::hash(String input) {
    unsigned char hash[SHA512_DIGEST_LENGTH];
    SHA512_CTX sha512;
    SHA512_Init(&sha512);
    SHA512_Update(&sha512, input.utf8().get_data(), input.length());
    SHA512_Final(hash, &sha512);

    String result;
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        result += String::format("%02x", hash[i]);
    }
    return result;
}

