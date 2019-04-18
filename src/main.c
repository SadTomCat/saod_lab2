#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include "hashtab.h"
#include "hash.h"

#define NUM_WORD 10

char* generation_word(char* word);
void generation_word2(char* str);

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
    char list[5][5] = 
    { 
        {'z', 'z', 'a', 'a', '\0'},
        {'e', 'w', 'h', 'r', '\0'},
        {'z', 'z', 'a', 'z', '\0'},
        {'e', 'a', 'a', 'a', '\0'},
        {'z', 'z', 'z', 'z', '\0'}
    };

    char* word;
    
    word = generation_word(word);
    tree = bstree_create(word, DJBHash(word, strlen(word)));
    printf("root: %d %s 0x%x 0x%x\n\n", tree->value, tree->key, tree->left, tree->right);

    bstree_add(tree, list[4], DJBHash(list[4], strlen(list[4])));
    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);


    bstree_add(tree, list[1], DJBHash(list[1], strlen(list[1])));
    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);

    bstree_add(tree, list[2], DJBHash(list[2], strlen(list[2])));
    node = bstree_lookup(tree, list[1]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    node = bstree_lookup(tree, list[2]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    bstree_add(tree, list[3], DJBHash(list[3], strlen(list[3])));
    node = bstree_lookup(tree, list[1]);
    printf("root: %d %s 0x%x 0x%x\n", node->value, node->key, node->left, node->right);

    printf("root: %d %s 0x%x 0x%x\n", tree->value, tree->key, tree->left, tree->right);
    node = bstree_max(tree);
    printf("%s\n", node->key);
    node = bstree_min(tree);
    printf("%s\n", node->key);

    free(word);

    return 0;
}

char* generation_word(char* word) 
{
    uint_least8_t i = 0;
    uint_least8_t num_ch = rand() % 12 + 6;
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


