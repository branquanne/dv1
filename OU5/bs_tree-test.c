#include "bs_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declarations of functions.
void print_array(int n, int a[]);
void swap(int *a, int *b);
void insert_value(int value, BSTreePos first_pos);
BSTreePos search_value(int value, BSTreePos first_pos);

// Assuming the structure is defined in bs_tree.h, include the definition here.
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} node;

int main(void)
{
    // Create an array with the values 1, 2, ..., 10 and print out the content.
    int n = 10;
    int arr[n];

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    print_array(n, arr);

    // Shuffle the values in the array and print out the content.
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % i;
        swap(&arr[j], &arr[i]);
    }

    print_array(n, arr);

    // Create a binary search tree and insert the values in the array.
    BSTree *tree = bs_tree_make(arr[0]);
    for (int i = 1; i < n; i++) {
        BSTreePos pos = bs_tree_root(tree);
        insert_value(arr[i], pos);
    }

    // Search the binary search tree for each of the values in the array and
    // print out the result of the search.
    for (int i = 0; i < n; i++) {
        BSTreePos pos = bs_tree_root(tree);
        if (search_value(arr[i], pos) == NULL) {
            printf("Value %d not found\n", arr[i]);
        }
        else {
            printf("Value %d found\n", arr[i]);
        }
    }

    // Search the binary search tree for a value that is not in the array and
    // print out the result of the search.
    BSTreePos pos = bs_tree_root(tree);
    int x = 99;
    if (search_value(x, pos) == NULL) {
        printf("Value %d not found\n", x);
    }
    else {
        printf("Value %d found\n", x);
    }

    // Destroy the binary search tree.
    bs_tree_destroy(tree);

    return 0;
}

// Print the array.
void print_array(int n, int a[])
{
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Swap the values.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert a value in the tree.
void insert_value(int value, BSTreePos first_pos)
{

    BSTreePos pos = first_pos;
    while (true) {
        if (value < pos->value) {
            if (bs_tree_has_left_child(pos)) {
                pos = bs_tree_left_child(pos);
            }
            else {
                pos = bs_tree_insert_left(value, pos);
                break;
            }
        }
        else {
            if (bs_tree_has_right_child(pos)) {
                pos = bs_tree_right_child(pos);
            }
            else {
                pos = bs_tree_insert_right(value, pos);
                break;
            }
        }
    }
}

// Search for a value in the tree.
BSTreePos search_value(int value, BSTreePos first_pos)
{
    BSTreePos pos = first_pos;
    while (pos != NULL) {
        if (value == pos->value) {
            return pos;
        }
        else if (value < pos->value) {
            pos = bs_tree_left_child(pos);
        }
        else {
            pos = bs_tree_right_child(pos);
        }
    }
    return NULL;
}
