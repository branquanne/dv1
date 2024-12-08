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
 * Date:        2024-12-08
 */

/* --- The following functions are declared in stack.h --- */

struct stack {
    int capacity;
    int size;
    double *data;
};

Stack *stack_create(void)
{
    Stack *s = malloc(sizeof(Stack));
    s->capacity = 1;
    s->size = 0;
    s->data = malloc(s->capacity * sizeof(double));
    return s;
}

void stack_destroy(Stack *s)
{
    free(s->data);
    free(s);
}

void stack_push(Stack *s, double value)
{
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity * sizeof(double));
    }
    s->data[s->size++] = value;
}

double stack_pop(Stack *s)
{
    return s->data[--s->size];
}

bool stack_is_empty(const Stack *s)
{
    if (s->size == 0) {
        return true;
    }
    return false;
}
