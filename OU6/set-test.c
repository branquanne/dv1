#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void check_set_empty(set *s1, set *s2);
set *check_set_single(void);
set *check_set_insert(void);
void check_set_union(set *s1, set *s2);
void check_set_intersection(set *s1, set *s2);
void check_set_difference(set *s1, set *s2);
void check_set_get_values(set *s);
void check_set_member_of(set *s);
void check_set_is_empty(set *s);
void check_set_choose(set *s);
void check_set_equal(set *s1, set *s2);
void check_set_subset(set *s1, set *s2);
void check_set_remove(set *s);
// void check_set_destroy(set *s);
void check_set_size(set *s);

struct set {
    int capacity;
    int size;
    char *array;
};

int main(void)
{
    // * Test SET_EMPTY() *
    set *s1 = set_empty();
    set *s2 = set_empty();

    // * Test SET_SINGLE() *
    set *s3 = check_set_single();

    // * Test SET_INSERT() *
    set *s4 = check_set_insert();

    // * Test SET_UNION() *
    set *s5 = set_empty();
    set *s6 = set_empty();
    for (int i = 0; i < 100; i++) {
        set_insert(i, s5);
    }
    for (int i = 50; i < 150; i++) {
        set_insert(i, s6);
    }
    check_set_union(s5, s6);

    // * Test SET_INTERSECTION() *
    check_set_intersection(s5, s6);

    // * Test SET_DIFFERENCE() *
    check_set_difference(s5, s6);

    // * Test SET_GET_VALUES() *
    check_set_get_values(s5);

    // * Test SET_MEMBER_OF() *
    check_set_member_of(s5);

    // * Test SET_IS_EMPTY() *
    set *s7 = set_empty();
    check_set_is_empty(s7);

    // * Test SET_CHOOSE() *
    check_set_choose(s5);

    // * Test SET_EQUAL() *
    set *s8 = set_empty();
    set *s9 = set_empty();
    for (int i = 0; i < 100; i++) {
        set_insert(i, s8);
        set_insert(i, s9);
    }
    check_set_equal(s8, s9);

    // * Test SET_SUBSET() *
    set *s10 = set_empty();
    for (int i = 50; i < 75; i++) {
        set_insert(i, s10);
    }
    check_set_subset(s10, s5);

    // * Test SET_SIZE() *
    check_set_size(s5);

    // * Test SET_DESTROY() using valgrind
    set_destroy(s1);
    set_destroy(s2);
    set_destroy(s3);
    set_destroy(s4);
    set_destroy(s5);
    set_destroy(s6);
    set_destroy(s7);
    set_destroy(s8);
    set_destroy(s9);
    set_destroy(s10);

    return 0;
}

void check_set_empty(set *s1, set *s2)
{
    bool is_ok = false;

    if (s1->size == 0 && s2->size == 0) {
        is_ok = true;
    }

    printf("The functioning of set_empty() has been tested ... \t\t%s", is_ok ? "OK" : "FAIL");
}

set *check_set_single(void)
{
    bool is_ok = false;

    set *s = set_single(1000);

    if (s->size == 1) {
        if ((s->array[1000 / 8] & (1 << (7 - 1000 % 8)))) {
            is_ok = true;
        }
    }
    printf("The functioning of set_single() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    return s;
}

set *check_set_insert(void)
{
    set *s = set_empty();
    bool is_ok = true;

    for (int i = 0; i < 100; i++) {
        set_insert(i, s);
    }

    if (s->size == 100) {
        for (int i = 0; i < 100; i++) {
            if (!(s->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
            }
        }
    }
    else {
        is_ok = false;
    }
    printf("The functioning of set_insert() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    return s;
}

void check_set_union(set *s1, set *s2)
{
    bool is_ok = true;

    set *s3 = set_union(s1, s2);
    if (s3->size == 150) {
        for (int i = 0; i < 150; i++) {
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
            }
        }
    }
    else {
        is_ok = false;
    }
    printf("The functioning of set_union() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");

    set_destroy(s3);
}

void check_set_intersection(set *s1, set *s2)
{
    bool is_ok = true;

    set *s3 = set_intersection(s1, s2);
    if (s3->size == 50) {
        for (int i = 50; i < 100; i++) {
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
            }
        }
    }
    else {
        is_ok = false;
    }
    printf("The functioning of set_intersection() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    set_destroy(s3);
}

void check_set_difference(set *s1, set *s2)
{
    bool is_ok = true;

    set *s3 = set_difference(s1, s2);
    if (s3->size == 50) {
        for (int i = 0; i < 50; i++) {
            if (!(s3->array[i / 8] & (1 << (7 - i % 8)))) {
                is_ok = false;
            }
        }
    }
    else {
        is_ok = false;
    }
    printf("The functioning of set_difference() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    set_destroy(s3);
}

void check_set_get_values(set *s)
{
    bool is_ok = true;

    int *values = set_get_values(s);

    for (int i = 0; i < 100; i++) {
        if (values[i] != i) {
            is_ok = false;
        }
    }
    printf("The functioning of set_get_values() has been tested ... \t%s\n", is_ok ? "OK" : "FAIL");

    free(values);
}
void check_set_member_of(set *s)
{
    bool is_ok = true;

    for (int i = 0; i < 100; i++) {
        if (!set_member_of(i, s)) {
            is_ok = false;
        }
    }
    printf("The functioning of set_member_of() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");
}
void check_set_is_empty(set *s)
{

    bool is_ok = (s->size == 0) ? true : false; // ! Maybe redundant !
    printf("The functioning of set_is_empty() has been tested ... \t\t%s\n", set_is_empty(s) && is_ok ? "OK" : "FAIL");
}
void check_set_choose(set *s)
{
    int value = set_choose(s);
    bool is_ok = set_member_of(value, s) && value == 0 ? true : false;

    printf("The functioning of set_choos() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");
}
void check_set_equal(set *s1, set *s2)
{
    bool is_ok = true;

    if (s1->size != s2->size) {
        is_ok = false;
    }
    else {
        for (int i = 0; i < s1->capacity; i++) {
            if (set_member_of(i, s1) != set_member_of(i, s2)) {
                is_ok = false;
                break;
            }
        }
    }

    printf("The functioning of set_equal() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");
}

void check_set_subset(set *s1, set *s2)
{
    printf("The functioning of set_subset() has been tested ... \t\t%s\n", set_subset(s1, s2) ? "OK" : "FAIL");
}

void check_set_remove(set *s)
{
    for (int i = 0; i < 100; i++) {
        set_insert(i, s);
    }
    set_remove(50, s);

    bool is_ok = !set_member_of(50, s) ? true : false;
    printf("The functioning of set_remove() has been tested ... \t\t%s\n", is_ok ? "OK" : "FAIL");
}

void check_set_size(set *s)
{
    bool is_ok = (s->size == 100) ? true : false;
    printf("The functioning of set_size() has been tested ... \t\t%s\n", (set_size(s) == 100 && is_ok) ? "OK" : "FAIL");
}