#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "hashtab.h"
#include "hash.h"

void hashtab_init(struct HashTab **hash_tab)
{
    if (hash_tab == NULL) {
        return;
    }

    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        hash_tab[i] = NULL;
    }
}

void hashtab_add_DJB(struct HashTab **hash_tab, char *key, int value)
{
    if (hash_tab == NULL) {
        return;
    }

    struct HashTab *node;

    uint32_t index = DJBHash(key, strlen(key));
    node = malloc(sizeof(*node));
    printf("%s %d", key, index);
    if (node != NULL && index < HASH_SIZE) {
        if (hash_tab[index] == NULL && index < HASH_SIZE - 1) {
            node->key = key;
            node->value = value;
            node->next = hash_tab[index + 1];
            hash_tab[index] = node;
            free(node);
            return;
        }

        if (hash_tab[index] == NULL && index == HASH_SIZE - 1) {
            node->key = key;
            node->value = value;
            node->next = NULL;
            hash_tab[index] = node;
            free(node);
            return;
        }  
        
        if (hash_tab[index] != NULL) {
    
            while (hash_tab[index] != NULL && index < HASH_SIZE) {
                index++;
            }

            if (index < HASH_SIZE - 1) {
                node->key = key;
                node->value = value;
                node->next = hash_tab[index + 1];
                hash_tab[index] = node;
                free(node);
                return;
            }
            
            if (index == HASH_SIZE - 1) {
                node->key = key;
                node->value = value;
                node->next = NULL;
                hash_tab[index] = node;
                free(node);
                return;
            }
        }
    }
}

void hashtab_add_KR(struct HashTab **hash_tab, char *key, int value)
{
    if (hash_tab == NULL) {
        return;
    }

    struct HashTab *node;

    uint32_t index = KRHash(key);
    node = malloc(sizeof(*node));
    printf("%s %d", key, index);
    if (node != NULL && index < HASH_SIZE) {
        if (hash_tab[index] == NULL && index < HASH_SIZE - 1) {
            node->key = key;
            node->value = value;
            node->next = hash_tab[index + 1];
            hash_tab[index] = node;
            free(node);
            return;
        }

        if (hash_tab[index] == NULL && index == HASH_SIZE - 1) {
            node->key = key;
            node->value = value;
            node->next = NULL;
            hash_tab[index] = node;
            free(node);
            return;
        }  
        
        if (hash_tab[index] != NULL) {
    
            while (hash_tab[index] != NULL && index < HASH_SIZE) {
                index++;
            }

            if (index < HASH_SIZE - 1) {
                node->key = key;
                node->value = value;
                node->next = hash_tab[index + 1];
                hash_tab[index] = node;
                free(node);
                return;
            }
            
            if (index == HASH_SIZE - 1) {
                node->key = key;
                node->value = value;
                node->next = NULL;
                hash_tab[index] = node;
                free(node);
                return;
            }
        }
    }
}

struct HashTab *hashtab_lookup_KR(struct HashTab **hash_tab, char *key) 
{
    if (hash_tab == NULL) {
        return;
    }

    struct HashTab *node;
    uint32_t index = KRHash(key);
    for (node = hash_tab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }
}

struct HashTab *hashtab_lookup_DJB(struct HashTab **hash_tab, char *key) 
{
    if (hash_tab == NULL) {
        return;
    }

    struct HashTab *node;
    uint32_t index = DJBHash(key, strlen(key));
    for (node = hash_tab[index]; node != NULL; node = node->next) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
    }
}

void hashtab_delete(struct HashTab **hashtab, char *key) 
{
    
}