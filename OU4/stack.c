#include "stack.h"
#include <stdlib.h>

struct stack {
  int capacity;
  int size;
  double *data;
};

Stack *stack_create(void) {}

void stack_destroy(Stack *s) {}

void stack_push(Stack *s, double value) {}

double stack_pop(Stack *s) {}

bool stack_is_empty(const Stack *s) {}
