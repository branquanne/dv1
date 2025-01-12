#include "set.h"
#include <stdlib.h>
#include <time.h>

/*
 * File:         set.c
 *
 * Description:  This file contains the implementation of the set module.
 *               The set module provides a set data structure and functions for
 * creating and manipulating sets. The set module provides functions for
 * creating a new empty set, creating a new set with a single element, inserting
 * a value into the set, creating the union, intersection, and difference of two
 * sets, checking if the set is empty, checking if the value is a member of the
 * set, choosing a value from the set, removing an element from the set,
 * checking if two sets are equal, checking if the first set is a subset of the
 * second set, and getting the size of the set. The set module also provides a
 * function for destroying the set and a function for getting the values of the
 * set.
 *
 * Author:       Bran Mjöberg Quanne
 *
 * Date:         2024-12-21
 */

struct set {
  int capacity;
  int size;
  char *array;
};

set *set_empty() {
  set *s = malloc(sizeof(set));
  s->capacity = 0;
  s->size = 0;
  s->array = NULL;
  return s;
}

set *set_single(const int value) {
  set *s = set_empty();
  set_insert(value, s);
  return s;
}

void set_insert(const int value, set *s) {
  if (!set_member_of(value, s)) {
    int bit_in_array = value;

    if (bit_in_array >= s->capacity) {
      int no_of_bytes = bit_in_array / 8 + 1;
      s->array = realloc(s->array, no_of_bytes);
      for (int i = s->capacity / 8; i < no_of_bytes; i++) {
        s->array[i] = 0;
      }
      s->capacity = no_of_bytes * 8;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    s->array[byte_no] = s->array[byte_no] | 1 << bit;
    s->size++;
  }
}

set *set_union(const set *const s1, const set *const s2) {
  set *s = set_empty();

  for (int i = 0; i < s1->capacity || i < s2->capacity; i++) {
    if (set_member_of(i, s1) || set_member_of(i, s2)) {
      set_insert(i, s);
    }
  }

  return s;
}

set *set_intersection(const set *const s1, const set *const s2) {
  set *s = set_empty();

  for (int i = 0; i < s1->capacity && i < s2->capacity; i++) {
    if (set_member_of(i, s1) && set_member_of(i, s2)) {
      set_insert(i, s);
    }
  }

  return s;
}

set *set_difference(const set *const s1, const set *const s2) {
  set *s = set_empty();

  for (int i = 0; i < s1->capacity; i++) {
    if (set_member_of(i, s1) && !set_member_of(i, s2)) {
      set_insert(i, s);
    }
  }

  return s;
}

bool set_is_empty(const set *const s) { return s->size == 0; }

bool set_member_of(const int value, const set *const s) {
  int bit_in_array = value;

  if (bit_in_array >= s->capacity) {
    return false;
  }

  int byte_no = bit_in_array / 8;
  int bit = 7 - bit_in_array % 8;
  char the_byte = s->array[byte_no];

  return the_byte & 1 << bit;
}

int set_choose(const set *const s) {
  srand(time(NULL));
  int *temp = set_get_values(s);
  int random = temp[rand() % s->size];
  free(temp);

  return random;
}

void set_remove(const int value, set *const s) {
  if (set_member_of(value, s)) {
    int bit_in_array = value;
    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    s->array[byte_no] = s->array[byte_no] & ~(1 << bit);
    s->size--;
  }
}

bool set_equal(const set *const s1, const set *const s2) {
  return set_subset(s1, s2) && set_subset(s2, s1);
}

bool set_subset(const set *const s1, const set *const s2) {
  for (int i = 0; i < s1->capacity; i++) {
    if (set_member_of(i, s1) && !set_member_of(i, s2)) {
      return false;
    }
  }

  return true;
}

int set_size(const set *const s) { return s->size; }

int *set_get_values(const set *const s) {
  int *values = malloc(s->size * sizeof(int));
  int j = 0;

  for (int i = 0; i < s->capacity; i++) {
    if (set_member_of(i, s)) {
      values[j] = i;
      j++;
    }
  }

  return values;
}

void set_destroy(set *s) {
  free(s->array);
  free(s);
}
