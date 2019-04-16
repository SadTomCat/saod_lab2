#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>
#include "gen_and_hash.h"

void generation_word2(char* str) {
    if (str[0] == 122 && str[1] == 122 && str[2] == 122 && str[3] == 122) {
        printf("ERROR: str = \'z\' \'z\' \'z\' \'z\'\n");
        return;
    }

    if (str[3] != 122) {
        str[3]++;
        return;
    }

    if (str[3] == 122 && str[2] != 122) {
        str[2]++;
        str[3] = 'a';
        return;
    }

    if (str[2] != 122 || str[1] != 122 || str[0] != 122 && str[3] == 122) {
        str[3] = 'a';
    }

    if (str[2] != 122) {
        str[2]++;
        return;
    }

    if (str[2] == 122 && str[1] != 122) {
        str[1]++;
        str[2] = 'a';
        str[3] = 'a';
        return;
    }

    if (str[1] != 122 || str[0] != 122 && str[2] == 122) {
        str[2] = 'a';
    }

    if (str[1] != 122) {
        str[1]++;
        return;
    }

    if (str[1] == 122 && str[0] != 122) {
        str[0]++;
        str[1] = 'a';
        str[2] = 'a';
        str[3] = 'a';
        return;
    }


    if (str[0] != 122 && str[1] == 122) {
        str[1] = 'a';
    }

    if (str[0] == 122 && str[1] == 122 && str[2] == 122 && str[3] == 122) {
        return;
    }
}

unsigned int DJBHash(char* str, unsigned int len) 
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

unsigned int KRHash(char *s) 
{
    unsigned int h = 0, hash_mul = 13131;
    while (*s)
        h = h * hash_mul + (unsigned int)*s++;
    return h;
}
