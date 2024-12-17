#include "set.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_set_empty();
bool check_set_single();
bool check_set_insert();
bool check_set_union();
bool check_set_intersection();
bool check_set_difference();
bool check_set_get_values();
bool check_set_member_of();
bool check_set_is_empty();
bool check_set_choose();
bool check_set_equal();
bool check_set_subset();
bool check_set_remove();
bool check_set_destroy();
bool check_set_size();

struct set {
    int capacity;
    int size;
    char *array;
};

int main(void)
{
    printf("The functioning of set_single() has been tested ... \t\t%s\n", check_set_single() ? "OK" : "FAIL");
    printf("The functioning of set_insert() has been tested ... \t\t%s\n", check_set_insert() ? "OK" : "FAIL");
    printf("The functioning of set_union() has been tested ... \t\t%s\n", check_set_union() ? "OK" : "FAIL");
    printf("The functioning of set_intersection() has been tested ... \t%s\n", check_set_intersection() ? "OK" : "FAIL");
    printf("The functioning of set_difference() has been tested ... \t%s\n", check_set_difference() ? "OK" : "FAIL");
    printf("The functioning of set_get_values() has been tested ... \t%s\n", check_set_get_values() ? "OK" : "FAIL");
    printf("The functioning of set_member_of() has been tested ... \t\t%s\n", check_set_member_of() ? "OK" : "FAIL");
    printf("The functioning of set_is_empty() has been tested ... \t\t%s\n", check_set_is_empty() ? "OK" : "FAIL");
    printf("The functioning of set_choose() has been tested ... \t\t%s\n", check_set_choose() ? "OK" : "FAIL");
    printf("The functioning of set_equal() has been tested ... \t\t%s\n", check_set_equal() ? "OK" : "FAIL");
    printf("The functioning of set_subset() has been tested ... \t\t%s\n", check_set_subset() ? "OK" : "FAIL");
    printf("The functioning of set_remove() has been tested ... \t\t%s\n", check_set_remove() ? "OK" : "FAIL");
    printf("The functioning of set_destroy() has been tested ... \t\t%s\n", check_set_destroy() ? "OK" : "FAIL");
    printf("The functioning of set_size() has been tested ... \t\t%s\n", check_set_size() ? "OK" : "FAIL");

    return 0;
}

bool check_set_empty(void)
{
    set *s1 = set_empty();
    set *s2 = set_empty();

    return (s1->size == 0 && s2->size == 0);
}

bool check_set_single(void)
{
    /* --- CHECK SET_SINGLE() FUNCTIONALITY --- */
    set *s3 = set_single(1000);
    set *s4 = set_single(10);

    if (s3->size == 1 && s4->size == 1) {
        if ((s3->array[1000 / 8] & (1 << (7 - 1000 % 8))) && (s4->array[10 / 8] & (1 << (7 - 10 % 8)))) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool check_set_insert(void)
{
    /* --- CHECK SET_INSERT() FUNCTIONALITY --- */
    set *s5 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s5);
    }

    if (s5->size == 100) {
        for (int i = 0; i < 100; i++) {
            if (!(s5->array[i / 8] & (1 << (7 - i % 8)))) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool check_set_union(void)
{
    /* --- CHECK SET_UNION() FUNCTIONALITY --- */
    set *s6 = set_empty();
    set *s7 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s6);
    }
    for (int i = 50; i < 150; i++) {
        set_insert(i, s7);
    }

    set *s8 = set_union(s6, s7);
    if (s8->size == 150) {
        for (int i = 0; i < 150; i++) {
            if (!(s8->array[i / 8] & (1 << (7 - i % 8)))) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool check_set_intersection(void)
{
    set *s9 = set_empty();
    set *s10 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s9);
    }
    for (int i = 50; i < 150; i++) {
        set_insert(i, s10);
    }

    set *s11 = set_intersection(s9, s10);
    if (s11->size == 50) {
        for (int i = 50; i < 100; i++) {
            if (!(s11->array[i / 8] & (1 << (7 - i % 8)))) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool check_set_difference(void)
{
    set *s12 = set_empty();
    set *s13 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s12);
    }
    for (int i = 50; i < 150; i++) {
        set_insert(i, s13);
    }

    set *s14 = set_difference(s12, s13);
    if (s14->size == 50) {
        for (int i = 0; i < 50; i++) {
            if (!(s14->array[i / 8] & (1 << (7 - i % 8)))) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool check_set_get_values(void)
{
    set *s15 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s15);
    }
    int *values = set_get_values(s15);

    for (int i = 0; i < 100; i++) {
        if (values[i] != i) {
            return false;
        }
    }

    return true;
}
bool check_set_member_of(void)
{
    set *s16 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s16);
    }
    for (int i = 0; i < 100; i++) {
        if (!set_member_of(i, s16)) {
            return false;
        }
    }

    return true;
}
bool check_set_is_empty(void)
{
    set *s17 = set_empty();
    return set_is_empty(s17);
}
bool check_set_choose(void)
{
    set *s18 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s18);
    }
    int value = set_choose(s18);

    return set_member_of(value, s18);
}
bool check_set_equal(void)
{
    set *s19 = set_empty();
    set *s20 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s19);
        set_insert(i, s20);
    }

    return set_equal(s19, s20);
}
bool check_set_subset(void)
{
    set *s21 = set_empty();
    set *s22 = set_empty();

    for (int i = 0; i < 100; i++) {
        set_insert(i, s21);
    }
    for (int i = 50; i < 75; i++) {
        set_insert(i, s22);
    }

    return set_subset(s22, s21);
}
bool check_set_remove(void)
{
    set *s23 = set_empty();
    for (int i = 0; i < 100; i++) {
        set_insert(i, s23);
    }
    set_remove(50, s23);

    return !set_member_of(50, s23);
}
bool check_set_destroy(void)
{
    set *s24 = set_empty();
    set_destroy(s24);
    return true; //! how to check if the set is destroyed?
}
bool check_set_size(void)
{
    set *s25 = set_empty();
    for (int i = 0; i < 100; i++) {
        set_insert(i, s25);
    }

    return set_size(s25) == 100;
}