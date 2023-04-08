#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <binary-file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 1;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Read the entire file into memory
    char *buffer = malloc(size);
    if (!buffer) {
        fprintf(stderr, "Out of memory\n");
        return 1;
    }
    if (fread(buffer, size, 1, file) != 1) {
        fprintf(stderr, "Could not read file\n");
        return 1;
    }

    // Encode the binary data as a base64-encoded string
    BIO *bio, *b64;
    BUF_MEM *bptr;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, buffer, size);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bptr);

    // Print out the base64-encoded string
    printf("%s\n", bptr->data);

    // Clean up resources
    free(buffer);
    BIO_free_all(bio);
    fclose(file);

    return 0;
}

