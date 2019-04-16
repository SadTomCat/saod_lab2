#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

struct bstree *bstree_create(char *key, int value) 
{
    struct bstree *node;

    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

void bstree_add(struct bstree *tree, char *key, int value) 
{
    if (tree == NULL) {
        return;
    }

    int cmp;
    struct bstree *parent, *node;
    while (tree != NULL) {
        parent = tree;
        cmp = strcmp(key, tree->key);

        if (cmp < 0) {
            tree = tree->left;
        } else if (cmp > 0) {
            tree = tree->right;
        } else {
            return;
        }
    } 

    cmp = strcmp(key, parent->key);
    node = bstree_create(key, value);
    if (cmp < 0) {
        parent->left = node;
    } 
    if (cmp > 0) {
        parent->right = node;
    }
}


struct bstree *bstree_lookup(struct bstree *tree, char *key) 
{
    if (tree == NULL) {
        return tree;
    }

    int cmp;
    while (tree != NULL) {
        cmp = strcmp(key, tree->key);
        if (cmp == 0) {
            return tree;
        }

        if (cmp < 0) {
            tree = tree->left;
        }

        if (cmp > 0) {
            tree = tree->right;
        }
    }

    return tree;
}

struct bstree *bstree_delete(struct bstree *tree, char *key) 
{
    if (tree == NULL) {
        return tree;
    }

    int cmp;
    struct bstree *parent, *min, *min_parent;
    while (strcmp(tree->key, key) != 0 && tree != NULL) {
        parent = tree;
        
        if (strcmp(tree->key, key) == -1) {
            tree = tree->left;
        }

        if (strcmp(tree->key, key) == 1) {
            tree = tree->right;
        }
    }

    if (tree == NULL) {
        return tree;
    }

    //first 
    if (tree->left == NULL && tree->right == NULL) {
        if (strcmp(tree->key, parent->key) == -1) {
            parent->left = NULL;
        }

        if (strcmp(tree->key, parent->key) == 1) {
            parent->right = NULL;
        }
        free(tree);
        return parent;
    }

    //second
    if (tree->left != NULL && tree->right == NULL) {
        parent->left = tree->left;
        free(tree);
        return parent;
    }

    if (tree->left == NULL && tree->right != NULL) {
        parent->right = tree->right;
        free(tree);
        return parent;
    }

    //third
    if (tree->left != NULL && tree->right != NULL) {
        min = tree->right;
        min_parent = min;

        if (min_parent->left != NULL) {
            min = min_parent->left;
            tree = min;
            while (min->left != NULL) {
                min_parent = min;
                min = min->left;
            }
            
            if (strcmp(tree->key, parent->key) == -1) {
                parent->left = min;
            }

            if (strcmp(tree->key, parent->key) == 1) {
                parent->right = min;
            }
        }
    }
}

struct bstree *bstree_min(struct bstree *tree) 
{
    if (tree == NULL) {
        return tree;
    }

    while (tree->left != NULL) {
        tree = tree->left;
    }  

    return tree;
}

struct bstree *bstree_max(struct bstree *tree) 
{
    if (tree == NULL) {
        return tree;
    } 

    while (tree->right != NULL) {
        tree = tree->right;
    }

    return tree;
}
