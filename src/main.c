#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "include/bstree.h"
#include "include/hashtab.h"
#include "include/hash.h"

#define DEL 10000

char* generation_word(char* word);
void generation_word2(char* str);
double wtime();

int main() 
{ 
    srand(time(NULL));
    char* word;
    char word2[5] = "aaaa";
    char word_list[HASH_SIZE][19];
    uint32_t rand_word, comparison;
    long double start_time, end_time, time, avr;
    struct bstree *tree, *node;
    struct HashTab *hash_tab[HASH_SIZE], *node_hash;
    
    //TASK 1    
    printf("TASK 1\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        word = generation_word(word);
        strcpy(word_list[i], word);
        free(word);
    }

    printf("TREE\n");
    tree = bstree_create(word_list[0], DJBHash(word_list[0], strlen(word_list[0])));
    printf("%s\n", tree->key);

    for (uint32_t i = 2; i < HASH_SIZE; i++) {
        bstree_add(tree, word_list[i - 1], DJBHash(word_list[i - 1], strlen(word_list[i - 1])));
        if (i % DEL == 0) {
            avr = 0;
            for (uint32_t j = 0; j < 10000; j++) {
                rand_word = rand() % (i - 2);
                start_time = wtime();
                node = bstree_lookup(tree, word_list[rand_word]);
                end_time = wtime();
                time = end_time - start_time;
                avr+= time;
            }
            avr = avr / 10000;
            printf("words = %d, average time %.10Lf\n", i, avr);
        } 
    }

    printf("HASH\n");
    uint32_t col = 10000;
    hashtab_init(hash_tab);
    for (uint32_t i = 0; i < HASH_SIZE; i++) {
        hashtab_add(hash_tab, word_list[i], DJBHash(word_list[i], strlen(word_list[i])));
    }

    for (int  i = 10000; i < HASH_SIZE; i+=10000) {
            avr = 0;
            for (uint32_t j = 0; j < 10000; j++) {
                rand_word = rand() % (i - 2);
                start_time = wtime();
                node_hash = hashtab_lookup(hash_tab, word_list[rand_word]);
                end_time = wtime();
                time = end_time - start_time;
                avr+= time;
            }
            avr = avr / 10000;
            printf("words = %d, average time %.10Lf\n", i, avr);
    }

    hashtab_clear(hash_tab);

/*
  //TASK 2
  printf("TASK 2\n");
    printf("TREE\n");

    strcpy(word_list[0], word2);
    for (uint32_t i = 1; i < HASH_SIZE - 1; i++) {
        generation_word2(word2);
        strcpy(word_list[i], word2);
    }

    tree = bstree_create(word_list[0], DJBHash(word_list[0], strlen(word_list[0])));
    for (uint32_t i = 1; i < HASH_SIZE - 1; i++) {
        bstree_add(tree, word_list[i], DJBHash(word_list[i], strlen(word_list[i])));
        if (i % DEL == 0) {
            start_time = wtime();
            node = bstree_lookup(tree, word_list[i]);
            end_time = wtime();
            time = end_time - start_time;
            printf("words = %d, time %.10Lf\n", i, time);
        } 
    }

    //hash
    printf("HASH\n");
    
    word = generation_word(word);
    while (DJBHash("aaaa", strlen("aaaa")) != DJBHash(word, strlen(word))) {
        word = generation_word(word);
    }
    strcpy(word_list[0], word);
    for (uint32_t i = 1; i < HASH_SIZE; i++) {
        strcpy(word_list[i], "aaaa");
    }

    hashtab_init(hash_tab);
    hashtab_add(hash_tab, word_list[0], DJBHash(word_list[0], strlen(word_list[0])));
   
    for (uint32_t i = 1; i < HASH_SIZE; i++) {
        hashtab_add(hash_tab, word_list[i], DJBHash(word_list[i], strlen(word_list[i])));
        if (i % DEL == 0) {
            start_time = wtime();
            node_hash = hashtab_lookup(hash_tab, word_list[0]);
            end_time = wtime();
            time = end_time - start_time;
            printf("words = %d, average time %.10Lf\n", i, time);
        }
    }
  */  
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

void generation_word2(char* str) 
{
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
