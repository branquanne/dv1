#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

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
