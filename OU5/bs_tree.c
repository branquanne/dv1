#include "bs_tree.h"
#include <stdlib.h>

// The type for the tree.
struct node {
  int value;
  struct node *left_child;
  struct node *right_child;
};

BSTree *bs_tree_make(int value) {
  BSTree *tree = malloc(sizeof(BSTree));
  tree->value = value;
  tree->left_child = NULL;
  tree->right_child = NULL;
  return tree;
}

BSTreePos bs_tree_insert_left(int value, BSTreePos pos) {
  BSTree *node = malloc(sizeof(BSTree));
  node->value = value;
  node->left_child = NULL;
  node->right_child = NULL;
  pos->left_child = node;
  return node;
}

BSTreePos bs_tree_insert_right(int value, BSTreePos pos) {
  BSTree *node = malloc(sizeof(BSTree));
  node->value = value;
  node->left_child = NULL;
  node->right_child = NULL;
  pos->right_child = node;
  return node;
}

int bs_tree_inspect_label(BSTreePos pos) { return pos->value; }

bool bs_tree_has_left_child(BSTreePos pos) { return pos->left_child != NULL; }

bool bs_tree_has_right_child(BSTreePos pos) { return pos->right_child != NULL; }

BSTreePos bs_tree_root(BSTree *tree) {
  if (tree == NULL) {
    return NULL;
  }
  return tree;
}

BSTreePos bs_tree_left_child(BSTreePos pos) {
  if (pos->left_child == NULL) {
    return NULL;
  }
  return pos->left_child;
}

BSTreePos bs_tree_right_child(BSTreePos pos) {
  if (pos->right_child == NULL) {
    return NULL;
  }
  return pos->right_child;
}

void bs_tree_destroy(BSTree *tree) {
  if (tree == NULL) {
    return;
  }
  bs_tree_destroy(tree->left_child);
  bs_tree_destroy(tree->right_child);
  free(tree);
}
