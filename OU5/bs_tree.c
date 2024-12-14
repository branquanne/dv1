#include "bs_tree.h"
#include <stdlib.h>

/*
* File:         bs_tree.c
*
* Description:  A binary search tree is a data structure that is used to store
*               values in a sorted order. The binary search tree is a tree where each node
*               has at most two children. The left child of a node contains a value that is
*               less than the value in the node, and the right child contains a value that is
*               greater than the value in the node. This file contains the implementation of
*               the binary search tree.
*
* Author:       Bran Mjöberg Quanne
*
* Date:        2024-12-13
*/

/* The structure for the binary search tree where each node consists of a value and pointers to its children. */
struct node {
    int value;
    struct node *left_child;
    struct node *right_child;
};

BSTree *bs_tree_make(int value)
{
    BSTree *tree = malloc(sizeof(BSTree));
    tree->value = value;
    tree->left_child = NULL;
    tree->right_child = NULL;
    return tree;
}

BSTreePos bs_tree_insert_left(int value, BSTreePos pos)
{
    BSTree *node = malloc(sizeof(BSTree));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    pos->left_child = node;
    return node;
}

BSTreePos bs_tree_insert_right(int value, BSTreePos pos)
{
    BSTree *node = malloc(sizeof(BSTree));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    pos->right_child = node;
    return node;
}

int bs_tree_inspect_label(BSTreePos pos) { return pos->value; }

bool bs_tree_has_left_child(BSTreePos pos) { return pos->left_child ? true : false; }

bool bs_tree_has_right_child(BSTreePos pos) { return pos->right_child ? true : false; }

BSTreePos bs_tree_root(BSTree *tree)
{
    return tree ? tree : NULL;
}

BSTreePos bs_tree_left_child(BSTreePos pos)
{
    return pos->left_child ? pos->left_child : NULL;
}

BSTreePos bs_tree_right_child(BSTreePos pos)
{
    return pos->right_child ? pos->right_child : NULL;
}

void bs_tree_destroy(BSTree *tree)
{
    if (!tree) {
        return;
    }

    bs_tree_destroy(tree->left_child);
    bs_tree_destroy(tree->right_child);
    free(tree);
}
