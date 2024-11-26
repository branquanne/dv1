#include "array.h"
#include <stdlib.h>
/*
 * Description:   This file handles the definitions of the functions used to create, manipulate and destroy a 2D array represented as a 1D array.
 *
 * Author:        Bran Mjöberg Quanne
 * Date:          2024-11-26

/* --- The following functions are declared in array.h --- */

Array *array_create(int n1, int n2)
{
    Array *arr = malloc(sizeof(Array));
    arr->data = calloc(n1 * n2, sizeof(int));
    arr->n1 = n1;
    arr->n2 = n2;
    return arr;
}

void array_destroy(Array *arr)
{
    free(arr->data);
    free(arr);
}

int array_rows(const Array *arr) { return arr->n1; }

int array_columns(const Array *arr) { return arr->n2; }

int array_get(const Array *arr, int i1, int i2)
{
    return arr->data[i1 * array_columns(arr) + i2];
}

void array_set(Array *arr, int i1, int i2, int value)
{
    arr->data[i1 * array_columns(arr) + i2] = value;
}
