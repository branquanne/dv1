#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
/**
 * @defgroup LIST_H list.h
 *
 * @brief Declarations used to represent a double linked list.
 *
 * A module that contains the declarations of structs and functions used to
 * create and manipulate a list. The module declarations are used by the files
 * list.c and main.c.
 *
 * @author Bran Mjöberg Quanne
 * @since 2024-11-15
 * @{
 *
 */

/**
 * @brief A structure used to represent a node in a list.
 *
 */
struct node {
    struct node *next; /**< A pointer to the next node in the list. */
    struct node *prev; /**< A pointer to the previous value in the list. */
    char *value;       /**< The value contained within the node */
};

/**
 * @brief A structure used to represent a list.
 *
 */
typedef struct list {
    struct node head; /**< A pointer to the head of the list. */
} List;

/**
 * @brief A structure used to represent a position in a list.
 *
 */
typedef struct list_pos {
    struct node *node; /**< A pointer to the node in the list. */
} ListPos;

/**
 * @brief Creates an empty list.
 *
 * Creates an empty list and allocates memory for the list.
 *
 * @param void
 *
 * @return Pointer to an empty list.
 *
 * @see list_destroy().
 *
 * @note User has to manually free the memory allocated by the list using list_destroy().
 */
List *list_create(void);

/**
 * @brief Destroys a list.
 *
 * Gets a list and frees all the nodes and the list itself.
 *
 * @param lst Pointer to a list.
 *
 * @return None.
 *
 * @see list_create().
 */
void list_destroy(List *lst);

/**
 * @brief Checks if a list is empty.
 *
 * Gets a list and checks if a list is empty.
 *
 * @param lst Pointer to a list.
 *
 * @return True if the list is empty and false if it isn´t.
 *
 * @note Usage may result in undefined behavior if the list is not initialized.
 */
bool list_is_empty(const List *lst);

/**
 * @brief Returns the position of the first element of the list.
 *
 * Gets a list and returns the position of the first element of the list.
 *
 * @param lst Pointer to a list.
 *
 * @return The position of the first element.
 *
 * @see list_end().
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the list is empty.
 */
ListPos list_first(List *lst);

/**
 * @brief Returns the position after the last element in the list.
 *
 * Gets a list and returns the position after the last element in the list.
 *
 * @param lst Pointer to a list.
 *
 * @return The position after the last element.
 *
 * @see list_first().
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the list is empty.
 */
ListPos list_end(List *lst);

/**
 * @brief Checks if two positions are equal.
 *
 * Checks if two positions are equal by comparing the positions of the nodes.
 *
 * @param p1 The first position.
 * @param p2 The second position.
 *
 * @return True if the positions are equal and false if they aren´t.
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the list is empty.
 */
bool list_pos_equal(ListPos p1, ListPos p2);

/**
 * @brief Moves to the next position.
 *
 * Moves to the next position by returning the next node of the current node.
 *
 * @param pos A position.
 *
 * @return The next position.
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the position is the last element.
 */
ListPos list_next(ListPos pos);

/**
 * @brief Moves to the previous position.
 *
 * Gets a position and moves to the previous position in the list.
 *
 * @param pos A position.
 *
 * @return The previous position.
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the position is the first element.
 */
ListPos list_prev(ListPos pos);

/**
 * @brief Inserts a value before a position.
 *
 * Gets a position and insert a value before that position.
 *
 * @param pos A position.
 * @param value A pointer to a value.
 *
 * @return The position of the new element.
 *
 * @see list_remove().
 *
 * @note Usage may result in undefined behavior if the list is not initialized.
 */
ListPos list_insert(ListPos pos, const char *value);

/**
 * @brief Removes a value at a position.
 *
 * Gets a position and removes a value at that position.
 *
 * @param pos A position.
 *
 * @return The position of the next element.
 *
 * @see list_insert().
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the list is empty.
 */
ListPos list_remove(ListPos pos);

/**
 * @brief Returns the value at a position.
 *
 * Gets a position and returns the value at that position.
 *
 * @param pos A position.
 *
 * @return The value at the position.
 *
 * @note Usage may result in undefined behavior if the list is not initialized and if the list is empty.
 */
const char *list_inspect(ListPos pos);
/**
 * @}
 */
#endif /* LIST_H */
