#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"
#include "hash.h"

void hashtab_init(struct HashTab **hash_tab)
{
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        hash_tab[i] = NULL;
    }
}

void hashtab_print(struct HashTab **hash_tab)
{   
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        if (hash_tab[i] == NULL) {
            printf("hash_tab[%d] = %p\n", i, &hash_tab[i]);
        } else {
            printf("hashatab[%d] key - %s, value - %d, next = %p\n", i, hash_tab[i]->key, 
                hash_tab[i]->value, hash_tab[i]->next);
        }
    }
    printf("\n");
}

void hashtab_add(struct HashTab **hash_tab, char *key, int value) 
{
    struct HashTab *node = malloc(sizeof(*node));
    uint32_t collision = 0;
    uint32_t index = DJBHash(key, strlen(key));
    //uint32_t index = KRHash(key);
    
    if (index >= HASH_SIZE) {
        printf("ERROR: hash more than max index %d\n", index);
        return;
    }

    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->next = hash_tab[index];
        hash_tab[index] = node;
    }
}

struct HashTab *hashtab_lookup(struct HashTab **hash_tab, char *key) 
{
    struct HashTab *node;
    uint32_t index = DJBHash(key, strlen(key));
    //uint32_t index = KRHash(key);

    for (node = hash_tab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }

    return NULL;
}

void hashtab_delete(struct HashTab **hash_tab, char *key) 
{
    struct HashTab *node, *prev = NULL;
    uint32_t index = DJBHash(key, strlen(key));
    //uint32_t index = KRHash(key);
    uint32_t count_free_place, sub_index;
    
    for (node = hash_tab[index]; node != NULL; node = node->next) {
        if (0 == strcmp(node->key, key)) {
            if (prev == NULL) {
                hash_tab[index] = node->next;
            } else {
                prev->next = node->next;
            }
            free(node);
            return;
        }
        prev = node;
    }
}

void hashtab_clear(struct HashTab **hash_tab) 
{
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        while (hash_tab[i] != NULL) {
            hashtab_delete(hash_tab, hash_tab[i]->key);
        }    
    }
} 
