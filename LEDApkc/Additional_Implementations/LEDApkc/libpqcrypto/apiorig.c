#include <stdio.h>
#include "ref/apiorig.h"

void main(int argc, char const *argv[])
{
    printf("CRYPTO_SECRETKEYBYTES=%d\n", CRYPTO_SECRETKEYBYTES);
    printf("CRYPTO_PUBLICKEYBYTES=%d\n", CRYPTO_PUBLICKEYBYTES);
    printf("CRYPTO_BYTES=%d\n", CRYPTO_BYTES);
    return 0;
}