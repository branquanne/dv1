#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @defgroup stack stack
 *
 * A stack is a data structure that allows elements to be inserted and removed
 * in a last-in-first-out (LIFO) order. This means that the last element that
 * was inserted into the stack is the first one to be removed.
 *
 * @author Bran Mjöberg Quanne
 * @since 2024-12-03
 * @{
 */

// The type for a stack.
typedef struct stack Stack;

// Create an empty stack.
Stack *stack_create(void);

// Destroy the stack.
void stack_destroy(Stack *s);

// Push a value onto the stack.
void stack_push(Stack *s, double value);

// Pop the value at the top of the stack.
double stack_pop(Stack *s);

// Check if the stack is empty.
bool stack_is_empty(const Stack *s);

#endif /* STACK_H */
