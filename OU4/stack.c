#include "stack.h"
#include <stdlib.h>

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
