#include "stack.h"
#include <stdlib.h>

/*
 * File :       stack.c
 *
 * Description: This file contains the implementation of the stack module.
 *              The stack is a data structure that allows elements to be inserted and removed in a last-in-first-out (LIFO) order.
 *              This means that the last element that was inserted into the stack is the first one to be removed.
 *
 * Author:      Bran Mjöberg Quanne
 *
 * Date:        2024-12-03
 */

// Define the stack structure.
struct stack {
    int capacity;
    int size;
    double *data;
};

// Create an empty stack.
Stack *stack_create(void)
{
    // Allocate memory for the stack.
    Stack *s = malloc(sizeof(Stack));
    s->capacity = 1;
    s->size = 0;
    // Allocate memory for the data.
    s->data = malloc(s->capacity * sizeof(double));
    return s;
}

// Destroy the stack.
void stack_destroy(Stack *s)
{
    // Free the memory used by the data.
    free(s->data);
    // Free the memory used by the stack.
    free(s);
}

// Push a value onto the stack.
void stack_push(Stack *s, double value)
{
    // Check if the stack is full.
    if (s->size >= s->capacity) {
        // Double the capacity of the stack.
        s->capacity *= 2;
        // Reallocate memory for the data.
        s->data = realloc(s->data, s->capacity * sizeof(double));
    }
    // Push the value onto the stack.
    s->data[s->size++] = value;
}

// Pop a value from the stack.
double stack_pop(Stack *s)
{
    // Pop the value from the stack and decrease the size.
    return s->data[--s->size];
}

// Check if the stack is empty.
bool stack_is_empty(const Stack *s)
{
    if (s->size == 0) {
        return true;
    }
    return false;
}
