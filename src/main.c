#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "bstree.h"
#include "hashtab.h"
#include "hash.h"

#define NUM_WORD 200000
#define DEL 10000

char* generation_word(char* word);
void generation_word2(char* str);
double wtime();

int main() 
{ 
    srand(time(NULL));
    char* word;
    char word_list[NUM_WORD][19];
    uint32_t rand_word, count = 0, test;
    long double start_time, end_time, time;
    struct bstree *tree, *node;
    struct HashTab hash_tab[HASH_SIZE], *node_hash;
    
    //TASK 1
    for (int i = 0; i < NUM_WORD; i++) {
        word = generation_word(word);
        strcpy(word_list[i], word);
        free(word);
        count++;
    }

    tree = bstree_create(word_list[0], DJBHash_BS(word_list[0], strlen(word_list[0])));
    for (uint32_t i = 2; i < NUM_WORD; i++) {
        bstree_add(tree, word_list[i - 1], DJBHash_BS(word_list[i - 1], strlen(word_list[i - 1])));
        if (i % DEL == 0) {
            rand_word = rand() % (i - 2);
            start_time = wtime();
            node = bstree_lookup(tree, word_list[rand_word]);
            end_time = wtime();
            time = end_time - start_time;
            printf("words = %d, avr. time %.9Lf\n", i, time);

        } 
    }


    hashtab_init(hash_tab);
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        hashtab_add_DBJ(hash_tab, word_list[i], DJBHash(word_list[i], strlen(word_list[i])));
    }
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        node_hash = hashtab_lookup_DJB(hash_tab, word_list[i]);
        if (node != NULL) {
            printf("%d %s %d\n", i, node_hash->key, node_hash->value);

        }
    }


/*
    //hash
    hashtab_init(hash_tab);

    char hash_word3[16] = "woconfsptxv";
    hashtab_add_DBJ(hash_tab, hash_word3, DJBHash(hash_word3, strlen(hash_word3)));

    char hash_word[16] = "kdmctrcemqhmvmw";
    hashtab_add_DBJ(hash_tab, hash_word, DJBHash(hash_word, strlen(hash_word)));
    
    char hash_word2[16] = "xuwkvmycubq";
    hashtab_add_DBJ(hash_tab, hash_word2, DJBHash(hash_word2, strlen(hash_word2)));

    node_hash = hashtab_lookup_DJB(hash_tab, "qewqwe");
    hashtab_print(hash_tab);
    printf("\nlookup: %s %d\n", node_hash->key, node_hash->value);

    hashtab_add_DBJ(hash_tab, "qewqwe", DJBHash("qewqwe", strlen("qewqwe")));
    hashtab_add_DBJ(hash_tab, "qewqwe", DJBHash("qewqwe", strlen("qewqwe")));
    hashtab_add_DBJ(hash_tab, "qewqwe", DJBHash("qewqwe", strlen("qewqwe")));
    hashtab_print(hash_tab);
*/
    //free(word);

    return 0;
}

char* generation_word(char* word) 
{
    uint_least8_t i = 0;
    uint_least8_t num_ch = rand() % 10 + 8;
    word = malloc(num_ch * sizeof(char));
    
    while (i < num_ch - 1) {
        word[i] = rand() % 25 + 'a';
        i++;
    }
    word[i] = '\0';

    return word;
}

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

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
