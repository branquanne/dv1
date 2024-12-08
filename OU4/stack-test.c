#include "stack.h"
#include <math.h>
#include <stdio.h>

/*
 * File :       stack-test.c
 *
 * Description: This file contains a test program for the stack module.
 *              The test program creates a stack and pushes 10 unique values onto the stack.
 *              The program then pops these values from the stack and verifies that they are the correct values.
 *              The program then checks if the stack is empty and prints the result.
 *
 *             The program is will print "PASS" if both tests are passed and "FAIL" if either one failed.
 *
 * Author:      Bran Mjöberg Quanne
 *
 * Date:        2024-12-08
 */

int main(void)
{ // Create an empty stack.
    Stack *s = stack_create();

    // Push the values 0.5, 0.25, ..., 0.0009765625 onto the stack.
    bool ok = true;
    for (int i = 0; i < 10; i++) {
        stack_push(s, pow(0.5, i + 1));
    }

    // Pop and verify the values in the stack.
    for (int i = 9; i >= 0; i--) {
        double value = stack_pop(s);

        // Verify that the value is correct.
        if (value != pow(0.5, i + 1)) {
            ok = false;
        }
    }

    // Verify that the stack is empty.
    bool check_empty = stack_is_empty(s);
    if (!check_empty) {
        ok = false;
    }

    // Print the result of the test.
    printf("Test the functioning of the stack ... %s\n", ok ? "PASS" : "FAIL");

    // Free the memory used by the stack.
    stack_destroy(s);

    return 0;
}
