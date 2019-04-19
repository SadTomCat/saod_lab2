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
            printf("hash_tab[%d] = NULL\n", i);
        } else {
            printf("hashatab[%d] key - %s, value - %d\n", i, hash_tab[i]->key, 
                hash_tab[i]->value);
        }
    }
}

void hashtab_add_DBJ(struct HashTab **hash_tab, char *key, int value) 
{
    struct HashTab *node = malloc(sizeof(*node));
    uint32_t index = DJBHash(key, strlen(key));
    
    if (index >= HASH_SIZE) {
        printf("ERROR: hash more than max index\n");
        return;
    }

    if (node != NULL) {
        if (hash_tab[index] == NULL) {
            node->key = key;
            node->value = value;
            hash_tab[index] = node;
            return;
        } else {
            while (hash_tab[index] != NULL && index < HASH_SIZE) {
                index++;
            }
            
            if (index == HASH_SIZE) {
                printf("ERROR: not found free place\n");
                return;
            }

            if (index < HASH_SIZE && hash_tab[index] == NULL) {
                node->key = key;
                node->value = value;
                hash_tab[index] = node;
                return;
            }
        }
    }
}

void hashtab_add_KR(struct HashTab **hash_tab, char *key, int value) 
{
    struct HashTab *node = malloc(sizeof(*node));
    uint32_t index = KRHash(key);

    if (index >= HASH_SIZE) {
        printf("ERROR: hash more than max index\n");
        return;
    }
    
    if (node != NULL) {
        if (hash_tab[index] == NULL) {
            node->key = key;
            node->value = value;
            hash_tab[index] = node;
        } else {
            while (hash_tab[index] != NULL && index < HASH_SIZE) {
                index++;
            }
            
            if (index == HASH_SIZE) {
                printf("ERROR: not found free place\n");
                return;
            }

            if (index < HASH_SIZE && hash_tab[index] == NULL) {
                node->key = key;
                node->value = value;
                hash_tab[index] = node;
            }
        }
    }
}


struct HashTab *hashtab_lookup_DJB(struct HashTab **hash_tab, char *key) 
{
    struct HashTab *node;
    uint32_t index = DJBHash(key, strlen(key));
    
    for (node = hash_tab[index]; node != NULL && index < HASH_SIZE; index++) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }

    return NULL;
}

struct HashTab *hashtab_lookup_KR(struct HashTab **hash_tab, char *key) 
{
    struct HashTab *node;
    uint32_t index = KRHash(key);
    uint32_t count_free_place, sub_index;
    
    for (node = hash_tab[index]; node != NULL && index < HASH_SIZE; index++) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }

    return NULL;
}

void hashtab_delete_DKB(struct HashTab **hash_tab, char *key) 
{
    struct HashTab *node, *prev = NULL;
    uint32_t index = DJBHash(key, strlen(key));
    uint32_t count_free_place, sub_index;
    
    for (node = hash_tab[index]; node != NULL && index < HASH_SIZE; index++) {
        if (strcmp(node->key, key) == 0) {
            
        }
    }
}