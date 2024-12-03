#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @defgroup stack_h STACK_H
 *
 * @brief The Stack module is a simple stack implementation.
 *
 * A stack is a data structure that allows elements to be inserted and removed
 * in a last-in-first-out (LIFO) order. This means that the last element that
 * was inserted into the stack is the first one to be removed.
 *
 * @author Bran Mjöberg Quanne
 * @since 2024-12-03
 * @{
 */

/**
 * @brief The type for a stack.
 *
 * The type for a stack.
 *
 * @note The implementation of the stack is hidden from the user of the module and has to be
 * defined in the implementation file.
 */
typedef struct stack Stack;

/**
 * @brief Create an empty stack.
 *
 * This function creates a new stack and allocates memory for it.
 *
 * @param None.
 *
 * @return A pointer to the newly created stack.
 *
 * @note The caller is responsible for deallocating the memory used by the stack. This can be done using stack_destroy().
 * @note The function does not check if the memory allocation is successful and thus it may result in an undefined behaviour.
 */
Stack *stack_create(void);

/**
 * @brief Destroy the stack.
 *
 * This function deallocates the memory used by the stack.
 *
 * @param s A pointer to the stack to be destroyed.
 *
 * @return None.
 *
 * @note The function does not check if the stack exists and thus it may result in an undefined behaviour.
 */
void stack_destroy(Stack *s);

/**
 * @brief Push a value onto the stack.
 *
 * This function pushes a value onto the stack.
 *
 * @param s A pointer to the stack.
 * @param value The value to be pushed onto the stack.
 *
 * @return None.
 *
 * @note The function does not check if the stack exists and thus it may result in an undefined behaviour.
 * @note The function does not check if the memory reallocation is successful and thus it may result in an undefined behaviour.
 * @note The function does not check if the value is a valid number and thus it may result in an undefined behaviour.
 *
 */
void stack_push(Stack *s, double value);

/**
 * @brief Pop the value at the top of the stack.
 *
 * This function pops the value at the top of the stack and returns it.
 *
 * @param s A pointer to the stack.
 *
 * @return The value at the top of the stack.
 *
 * @note The function does not check if the stack exists and thus it may result in an undefined behaviour.
 * @note The function does not check if the stack is empty and thus it may result in an undefined behaviour.
 */
double stack_pop(Stack *s);

/**
 * @brief Check if the stack is empty.
 *
 * This function checks if the stack is empty.
 *
 * @param s A pointer to the stack.
 *
 * @return True if the stack is empty, otherwise false.
 *
 * @note The function does not check if the stack exists and thus it may result in an undefined behaviour.
 */
bool stack_is_empty(const Stack *s);

#endif /* STACK_H */
