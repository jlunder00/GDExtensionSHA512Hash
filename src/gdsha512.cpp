#include "gdsha512.h"
#include <openssl/sha.h>
#include <openssl/evp.h>

using namespace godot;

void GDSha512::_bind_methods() {
    ClassDB::bind_method(D_METHOD("hash", "input"), &GDSha512::hash);
}

GDSha512::GDSha512(){
  //constructor  
}

GDSha512::~GDSha512(){
  //destructor
}

String GDSha512::hash(const String& input) {
    unsigned char output[SHA512_DIGEST_LENGTH]; // Output buffer for the hash
    EVP_MD_CTX* ctx = EVP_MD_CTX_new(); // Create a context for the hash operation

    if (ctx == nullptr) {
        return ""; // Failed to create context, handle error appropriately
    }

    if (EVP_DigestInit_ex(ctx, EVP_sha512(), nullptr) != 1) {
        EVP_MD_CTX_free(ctx);
        return ""; // Initialization failed
    }

    if (EVP_DigestUpdate(ctx, input.utf8().get_data(), input.length()) != 1) {
        EVP_MD_CTX_free(ctx);
        return ""; // Hashing failed
    }

    unsigned int lengthOfHash = 0;
    if (EVP_DigestFinal_ex(ctx, output, &lengthOfHash) != 1) {
        EVP_MD_CTX_free(ctx);
        return ""; // Finalizing hash failed
    }

    EVP_MD_CTX_free(ctx); // Clean up the context

    // Convert the hash to a hexadecimal string
    String result;
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        result += String::num_uint64(output[i], 16).pad_zeros(2);
    }
    return result;
}

