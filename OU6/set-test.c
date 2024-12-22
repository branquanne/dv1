#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * File:         set-test.c
 *
 * Description:  This file contains a test program for the set module. The test program tests the functions in the set module.
 *               The test program tests the creation of sets, insertion of elements into the sets, and tests set operations such as union, intersection, and difference.
 *               The test program also tests the functions that check if the set is empty, if the value is a member of the set,
 *               if the sets are equal, if the first set is a subset of the second set, and if the set is empty. Lastly, the test program tests the functions that choose a value from the set,
 *               remove an element from the set, and get the size of the set. The test program prints OK if the functions work as expected, otherwise FAIL.
 *
 * Author:       Bran Mjöberg Quanne
 *
 * Date:         2024-12-22
 */

void check_set_empty();
void check_set_single();
void check_set_insert();
void check_set_union();
void check_set_intersection();
void check_set_difference();
void check_set_get_values();
void check_set_member_of();
void check_set_is_empty();
void check_set_choose();
void check_set_equal();
void check_set_subset();
void check_set_remove();
void check_set_size();
void populate_set(set *s, int start, int end);

struct set {
    int capacity;
    int size;
    char *array;
};

/*
 * Description: The main function that tests the set module.
 *
 * Input:       None.
 *
 * Output:      0 if the program runs successfully.
 */
int main(void)
{
    // Check if the created set is empty
    check_set_empty();

    // Check if the set with a single element is created
    check_set_single();

    // Check if the element is inserted into the set
    check_set_insert();

    // Check if the union of the two sets is correct
    check_set_union();

    // Check if the intersection of the two sets is correct
    check_set_intersection();

    // Check if the difference of the two sets is correct
    check_set_difference();

    // Check if the values in the set are correct
    check_set_get_values();

    // Check if the value is a member of the set
    check_set_member_of();

    // Check if the set is empty
    check_set_is_empty();

    // Check if the value is chosen from the set
    check_set_choose();

    // Check if the sets are equal
    check_set_equal();

    // Check if the first set is a subset of the second set
    check_set_subset();

    // Check if the element is removed from the set
    check_set_remove();

    // Check if the size of the set is correct
    check_set_size();

    return 0;
}

/*
 * Description: Check if the created set is empty.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_empty()
{
    bool is_ok = true;

    // Create two empty sets
    set *s1 = set_empty();
    set *s2 = set_empty();

    // Check if the sets are empty
    if (s1->size != 0 || s2->size != 0) {
        is_ok = false;
    }

    // Insert an element to the second set
    set_insert(10, s2);

    // Check if the second set is not empty
    if (s2->size == 0) {
        is_ok = false;
    }

    // Print OK if the conditions are met, otherwise FAIL
    printf("The functioning of set_empty() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s1);
    set_destroy(s2);
}

/*
 * Description: Check if the set with a single element is created.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_single()
{
    bool is_ok = true;

    // Create a set with a single element, 1000
    set *s = set_single(1000);

    // Check if the size is 1 and the element is correct
    if (s->size == 1) {

        // If the element is incorrect, set is_ok to false
        if (!(s->array[1000 / 8] & (1 << (7 - 1000 % 8)))) {
            is_ok = false;
        }
    }
    else {
        is_ok = false;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_single() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the element is inserted into the set.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_insert()
{
    bool is_ok = true;

    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set (The helper function populate_set is using set_insert)
    populate_set(s, 0, 100);

    // Check if the size is 100 and the elements are correct
    if (s->size == 100) {
        for (int i = 0; i < 100; i++) {

            // If the element is not correct, set is_ok to false and break the loop
            if (!(s->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
                break;
            }
        }
    }
    else {
        is_ok = false;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_insert() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the union of the two sets is correct.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_union()
{
    bool is_ok = true;

    // Create two sets with known relationships
    set *s1 = set_empty();
    set *s2 = set_empty();

    // Add 100 elements to the sets
    populate_set(s1, 0, 100);
    populate_set(s2, 50, 150);

    // Create a set with the union of the two sets
    set *s3 = set_union(s1, s2);

    // Check if the size is 150 since the union of the two sets is 150
    if (s3->size == 150) {
        for (int i = 0; i < 150; i++) {

            // If the element is not correct, set is_ok to false and break the loop
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
                break;
            }
        }
    }
    else {
        is_ok = false;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_union() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s1);
    set_destroy(s2);
    set_destroy(s3);
}

/*
 * Description: Check if the intersection of the two sets is correct.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_intersection()
{
    bool is_ok = true;

    // Create two sets with known relationships
    set *s1 = set_empty();
    set *s2 = set_empty();

    // Add 100 elements to the sets
    populate_set(s1, 0, 100);
    populate_set(s2, 50, 150);

    // Create a set with the intersection of the two sets
    set *s3 = set_intersection(s1, s2);

    // Check if the size is 50 since the intersection of the two sets is 50
    if (s3->size == 50) {
        for (int i = 50; i < 100; i++) {

            // If the element is not correct, set is_ok to false and break the loop
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
                break;
            }
        }
    }
    else {
        is_ok = false;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_intersection() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s1);
    set_destroy(s2);
    set_destroy(s3);
}

/*
 * Description: Check if the difference of the two sets is correct.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_difference()
{
    bool is_ok = true;

    // Create two sets with known relationships
    set *s1 = set_empty();
    set *s2 = set_empty();

    // Add 100 elements to the sets
    populate_set(s1, 0, 100);
    populate_set(s2, 50, 150);

    // Create a set with the difference of the two sets
    set *s3 = set_difference(s1, s2);

    // Check if the size is 50 since the difference of the two sets is 50
    if (s3->size == 50) {
        for (int i = 0; i < 50; i++) {

            // If the element is not correct, set is_ok to false and break the loop
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
                break;
            }
        }
    }
    else {
        is_ok = false;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_difference() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s1);
    set_destroy(s2);
    set_destroy(s3);
}

/*
 * Description: Check if the values in the set are correct.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_get_values()
{
    bool is_ok = true;

    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set
    populate_set(s, 0, 100);

    // Get the values from the set
    int *values = set_get_values(s);

    // Check if the values are correct
    for (int i = 0; i < 100; i++) {

        // If the value is not correct, set is_ok to false and break the loop
        if (values[i] != i) {
            is_ok = false;
            break;
        }
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_get_values() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    free(s);
    free(values);
}

/*
 * Description: Check if the value is a member of the set.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_member_of()
{
    bool is_ok = true;

    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set
    populate_set(s, 0, 100);

    // Check if the elements are members of the set
    for (int i = 0; i < 100; i++) {

        // If the element is not a member of the set, set is_ok to false and break the loop
        if (!set_member_of(i, s)) {
            is_ok = false;
            break;
        }
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_member_of() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the set is empty.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_is_empty()
{
    // Create an empty set
    set *s = set_empty();

    // Check if the set is empty
    bool is_empty = set_is_empty(s);
    bool is_not_empty = false;

    // Add an element to the set
    set_insert(10, s);

    // Check if the set is not empty
    if (!set_is_empty(s)) {
        is_not_empty = true;
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_is_empty() has been tested ... \t\t%s\n", is_empty && is_not_empty ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the value is chosen from the set.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_choose()
{
    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set
    populate_set(s, 0, 100);

    // Choose a value from the set
    int value = set_choose(s);

    // Check if the value is a member of the set and if the value is 0
    bool is_ok = set_member_of(value, s) && value == 0 ? true : false;

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_choos() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the sets are equal.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_equal()
{
    bool is_ok = true;

    // Create two sets with the same elements
    set *s1 = set_empty();
    set *s2 = set_empty();

    // Add 100 elements to the sets
    populate_set(s1, 0, 100);
    populate_set(s2, 0, 100);

    // Check if the size is the same
    if (s1->size != s2->size) {
        is_ok = false;
    }
    else {
        // Check if the elements are the same
        for (int i = 0; i < s1->capacity; i++) {

            // If the elements are not the same, set is_ok to false and break the loop
            if (set_member_of(i, s1) != set_member_of(i, s2)) {
                is_ok = false;
                break;
            }
        }
    }

    // Print OK if the condition is met, otherwise FAIL
    printf("The functioning of set_equal() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s1);
    set_destroy(s2);
}

/*
 * Description: Check if the first set is a subset of the second set.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_subset()
{
    bool is_ok = true;

    // Create sets with known relationships
    set *subset = set_empty();
    set *superset = set_empty();
    set *non_subset = set_empty();

    // Add elements to the subset and superset
    populate_set(subset, 0, 50);
    populate_set(superset, 0, 50);

    // Add additional elements to the superset
    for (int i = 50; i < 100; i++) {
        set_insert(i, superset);
    }

    // Add different elements to the non_subset
    for (int i = 100; i < 150; i++) {
        set_insert(i, non_subset);
    }

    // Test if subset is a subset of superset
    if (!set_subset(subset, superset)) {
        is_ok = false;
    }

    // Test if superset is not a subset of subset
    if (set_subset(superset, subset)) {
        is_ok = false;
    }

    // Test if non_subset is not a subset of superset
    if (set_subset(non_subset, superset)) {
        is_ok = false;
    }

    // Print OK if all tests pass, otherwise FAIL
    printf("The functioning of set_subset() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(subset);
    set_destroy(superset);
    set_destroy(non_subset);
}

/*
 * Description: Check if the element is removed from the set.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_remove()
{
    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set
    populate_set(s, 0, 100);

    // Remove the element 50 from the set
    set_remove(50, s);

    // Check if the element 50 is not in the set
    bool is_ok = !set_member_of(50, s);

    // Check if the size of the set is now 99
    if (s->size != 99) {
        is_ok = false;
    }

    // Check if other elements are still in the set
    for (int i = 0; i < 100; i++) {
        if (i != 50 && !set_member_of(i, s)) {
            is_ok = false;
            break;
        }
    }

    // Print OK or FAIL if the condition is met
    printf("The functioning of set_remove() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Check if the size of the set is correct.
 *
 * Input:       None.
 *
 * Output:      None.
 */
void check_set_size()
{
    // Create a set
    set *s = set_empty();

    // Add 100 elements to the set
    populate_set(s, 0, 100);

    // Check if the size is 100
    bool is_ok = (set_size(s) == 100);

    // Print OK or FAIL depending on the condition
    printf("The functioning of set_size() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    // Clean up
    set_destroy(s);
}

/*
 * Description: Populate the set with elements from start to end but not including the end value.
 *
 * Input:       s - A pointer to the set.
 *              start - The start value.
 *              end - The end value.
 *
 * Output:      None.
 */
void populate_set(set *s, int start, int end)
{
    for (int i = start; i < end; i++) {
        set_insert(i, s);
    }
}