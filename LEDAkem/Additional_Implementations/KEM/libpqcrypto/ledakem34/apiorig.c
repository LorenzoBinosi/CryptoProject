#include <stdio.h>
#include "ref/apiorig.h"

int main(int argc, char const *argv[])
{
    printf("#define CRYPTO_SECRETKEYBYTES %d\n", CRYPTO_SECRETKEYBYTES);
    printf("#define CRYPTO_PUBLICKEYBYTES %d\n", CRYPTO_PUBLICKEYBYTES);
    printf("#define CRYPTO_BYTES %d\n", CRYPTO_BYTES);
    printf("#define CRYPTO_CIPHERTEXTBYTES %d\n", CRYPTO_CIPHERTEXTBYTES);
    return 0;
}