#ifndef BS_TREE_H
#define BS_TREE_H
#include <stdbool.h>

/**
 * @file bs_tree.h
 *
 * @brief The interface for the binary search tree.
 *
 * The interface defines the functions to work with a binary search tree. The
 * binary search tree is a binary tree where the left child is less than the
 * parent and the right child is greater than the parent.
 *
 * @author Bran Mjöberg Quanne
 *
 * @since 2024-12-10
 */

/**
 * @brief The type for the binary search tree.
 *
 * The implementation of the binare search tree is hidden from the user.
 * The user has to define the tree in the implementation files.
 */
typedef struct node BSTree;

/**
 * @brief The type for the position in the binary search tree.
 *
 * The implementation of the position in the binary search tree is hidden from
 * the user. The user has to define the position in the implementation files.
 */
typedef struct node *BSTreePos;

/**
 * @brief Create and return a binary search tree.
 *
 * The function creates a binary search tree with the value in the root-node.
 *
 * @param value The value to store in the root-node.
 *
 * @return The binary search tree.
 *
 * @note The function allocates memory for the binary search tree. The user is
 * responsible for deallocating the memory by calling bs_tree_destroy().
 *
 */
BSTree *bs_tree_make(int value);

/**
 * @brief Insert a node with as the left child to a node.
 *
 * The function inserts a node with a value as the left child to the node with
 * position pos.
 *
 * @param value The value to store in the node.
 * @param pos The position of the node to insert the new node as the left child.
 * @return The position of the new node.
 *
 * @note The function allocates memory for the new node. The user is responsible
 * for deallocating the memory by calling bs_tree_destroy().
 */
BSTreePos bs_tree_insert_left(int value, BSTreePos pos);

/**
 * @brief Insert a node with as the right child to a node.
 *
 * The function inserts a node with a value as the right child to the node with
 * position pos.
 *
 * @param value The value to store in the node.
 * @param pos The position of the node to insert the new node as the right child.
 * @return The position of the new node.
 *
 * @note The function allocates memory for the new node. The user is responsible
 * for deallocating the memory by calling bs_tree_destroy().
 */
BSTreePos bs_tree_insert_right(int value, BSTreePos pos);

/**
 * @brief Get the value at the position.
 *
 * The function returns the value at the position pos.
 *
 * @param pos The position of the node.
 * @return The value at the position.
 *
 * @note The function does not check if the position is NULL.
 */
int bs_tree_inspect_label(BSTreePos pos);

/**
 * @brief Check if the node at the position has a left child.
 *
 * The function checks if the node at the position pos has a left child.
 *
 * @param pos The position of the node.
 * @return True if the node has a left child, otherwise false.
 *
 * @see bs_tree_has_right_child()
 */
bool bs_tree_has_left_child(BSTreePos pos);

/**
 * @brief Check if the node at the position has a right child.
 *
 * The function checks if the node at the position pos has a right child.
 *
 * @param pos The position of the node.
 * @return True if the node has a right child, otherwise false.
 *
 * @see bs_tree_has_left_child()
 */
bool bs_tree_has_right_child(BSTreePos pos);

/**
 * @brief Get the position of the root.
 *
 * The function returns the position of the root in the binary search tree.
 *
 * @param tree The binary search tree.
 * @return The position of the root.
 *
 *
 */
BSTreePos bs_tree_root(BSTree *tree);

/**
 * @brief Get the position of the left child to a node.
 *
 * The function returns the position of the left child to the node with position
 * pos.
 *
 * @param pos The position of the node.
 * @return The position of the left child.
 */
BSTreePos bs_tree_left_child(BSTreePos pos);

/**
 * @brief Get the position of the right child to a node.
 *
 * The function returns the position of the right child to the node with position
 * pos.
 *
 * @param pos The position of the node.
 * @return The position of the right child.
 */
BSTreePos bs_tree_right_child(BSTreePos pos);

/**
 * @brief Destroy the binary search tree.
 *
 * The function deallocates the entire binary search tree.
 *
 * @param tree The binary search tree.
 */
void bs_tree_destroy(BSTree *tree);
/**
 * @}
 */
#endif /* BS_TREE_H */
