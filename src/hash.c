#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include "include/hash.h"

unsigned int DJBHash(char* str, unsigned int len) 
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash % HASH_SIZE;
}


unsigned int KRHash(char *s) 
{
    unsigned int h = 0, hash_mul = 13131;
    while (*s)
        h = h * hash_mul + (unsigned int)*s++;
    return h % HASH_SIZE;
}
