#include "bs_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
* File:         bs_tree-test.c
*
* Description:  A program that creates a binary search tree and inserts values in the tree. 
*               The program then searches for the values in the tree.
* 
* Author:       Bran Mjöberg Quanne
*   
* Date:        2024-12-13
*/

// Declarations of functions.
void print_array(int n, int a[]);
void swap(int *a, int *b);
void insert_value(int value, BSTreePos first_pos);
BSTreePos search_value(int value, BSTreePos first_pos);

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

/* The following functions were implemented by Bran Mjöberg Quanne */ 

/*
* Description: Insert a value in the search tree.
*
* Input:       value - The value to insert.
*              first_pos - The position of the first node.
* 
* Output:      The position of the new node.
*/
void insert_value(int value, BSTreePos first_pos)
{
    while (true) {
        if (value < bs_tree_inspect_label(first_pos)) {
            if (bs_tree_has_left_child(first_pos)) {
                first_pos = bs_tree_left_child(first_pos);
            }
            else {
                first_pos = bs_tree_insert_left(value, first_pos);
                break;
            }
        }
        else {
            if (bs_tree_has_right_child(first_pos)) {
                first_pos = bs_tree_right_child(first_pos);
            }
            else {
                first_pos = bs_tree_insert_right(value, first_pos);
                break;
            }
        }
    }
}

/*
* Description: Search for a specified value in the search tree.
* 
* Input:       value - The value to search for.
*              first_pos - The position of the first node.
*
* Output:      The position of the node with the specified value.
*/
BSTreePos search_value(int value, BSTreePos first_pos)
{
    while (first_pos != NULL) {
        if (value == bs_tree_inspect_label(first_pos)) {
            return first_pos;
        }
        else if (value < bs_tree_inspect_label(first_pos)) {
            first_pos = bs_tree_left_child(first_pos);
        }
        else {
            first_pos = bs_tree_right_child(first_pos);
        }
    }
    return NULL;
}
