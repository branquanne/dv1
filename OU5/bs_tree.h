#ifndef BS_TREE_H
#define BS_TREE_H

#include <stdbool.h>

// The type for the tree.
typedef struct node BSTree;

// The type for a tree position.
typedef struct node *BSTreePos;

// Create and return a binary search tree with the value in a root-node.
BSTree *bs_tree_make(int value);

// Insert a node with the value as the left child to the node with position pos.
BSTreePos bs_tree_insert_left(int value, BSTreePos pos);

// Insert a node with the value as the right child to the node with position
// pos.
BSTreePos bs_tree_insert_right(int value, BSTreePos pos);

// Get the value at the position.
int bs_tree_inspect_label(BSTreePos pos);

// Check if the node at the position has a left child.
bool bs_tree_has_left_child(BSTreePos pos);

// Check if the node at the position has a right child.
bool bs_tree_has_right_child(BSTreePos pos);

// Get the position of the root.
BSTreePos bs_tree_root(BSTree *tree);

// Get the position of the left child to the node with position pos.
BSTreePos bs_tree_left_child(BSTreePos pos);

// Get the position of the right child to the node with position pos.
BSTreePos bs_tree_right_child(BSTreePos pos);

// Deallocate the binary search tree.
void bs_tree_destroy(BSTree *tree);

#endif /* BS_TREE_H */
