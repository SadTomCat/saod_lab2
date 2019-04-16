#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include "hashtab.h"
#include "gen_and_hash.h"

#define NUM_WORD 10

void generation_word(char** word);

int main() 
{ 
    srand(time(NULL));
    /*for (uint32_t i = 0; i < 2; i++) {
        generation_word(&word);  
        printf("%s\n", word);
        free(word);
    } 

    generation_word(&word);  
    printf("%s\n", word);
    uint_least8_t len = strlen(word);
    printf("%d %d\n", len, DJBHash(word, len));
    printf("%d %d\n", len, KRHash(word));
    free(word);*/

    struct bstree *tree, *node;
    char word[5][5] = 
    { 
        {'z', 'z', 'a', 'a', '\0'},
        {'e', 'w', 'h', 'r', '\0'},
        {'z', 'z', 'a', 'z', '\0'},
        {'e', 'a', 'a', 'a', '\0'},
        {'z', 'z', 'z', 'z', '\0'}
    };

    char words[NUM_WORD][19];

    for (int i = 0; i < NUM_WORD; i++) {
        generation_word(words);
        printf("%s\n", words[i]);
    } 
       
    tree = bstree_create(word[0], DJBHash(word[0], strlen(word[0])));
    printf("root: %d %s 0x%x 0x%x\n\n", tree->value, tree->key, tree->left, tree->right);

    bstree_add(tree, word[4], DJBHash(word[4], strlen(word[4])));
    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);


    bstree_add(tree, word[1], DJBHash(word[1], strlen(word[1])));
    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);

    bstree_add(tree, word[2], DJBHash(word[2], strlen(word[2])));
    node = bstree_lookup(tree, word[1]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    node = bstree_lookup(tree, word[2]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    bstree_add(tree, word[3], DJBHash(word[3], strlen(word[3])));
    node = bstree_lookup(tree, word[1]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);
    node = bstree_max(tree);
    printf("%s\n", node->key);
    node = bstree_min(tree);
    printf("%s\n", node->key);


    return 0;
}

void generation_word(char** word) 
{
    uint_least8_t i = 0;
    uint_least8_t num_ch = rand() % 12 + 6;
    *word = malloc(num_ch * sizeof(char));
    
    while (i < num_ch - 1) {
        word[i] = rand() % 25 + 'a';
        i++;
    }
    word[i] = '\0';
}


