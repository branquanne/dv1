#include "stack.h"
#include <math.h>
#include <stdio.h>

struct stack {
    int capacity;
    int size;
    double *data;
};

int main(void)
{
    struct stack *s = stack_create();

    for (int i = 0; i < 10; i++) {
        stack_push(s, pow(0.5, i + 1));
        printf("Pushing value %lf\n", pow(0.5, i + 1));
    }

    for (int i = 0; i < 10; i++) {
        stack_pop(s);
        printf("Popping value %lf\n", s->data[s->size]);
    }

    bool check_empty = stack_is_empty(s);
    if (check_empty) {
        printf("Stack is empty, the size is %d\n", s->size);
    }

    stack_destroy(s);

    return 0;
}
