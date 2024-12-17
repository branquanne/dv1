#include <stdlib.h>
#include "set.h"

struct set {
    int capacity;
    int size;
    char *array;
};


set *set_empty()
{
	set *s = malloc(sizeof(set));
	s->capacity = 0;
	s->size = 0;
	s->array = NULL;
	return s;
}


set *set_single(const int value)
{
	set *s = set_empty();
	set_insert(value, s);
	return s;
}


void set_insert(const int value, set *s)
{
    if (!set_member_of(value, s)) {
        int bit_in_array = value; // To make the code easier to read

        // Increase the capacity if necessary
        if (bit_in_array >= s->capacity) {
            int no_of_bytes = bit_in_array / 8 + 1;
            s->array = realloc(s->array, no_of_bytes);
            for (int i = s->capacity / 8 ; i < no_of_bytes ; i++) {
                s->array[i] = 0;
            }
            s->capacity = no_of_bytes * 8;
        }

        // Set the bit
        int byte_no = bit_in_array / 8;
        int bit = 7 - bit_in_array % 8;
        s->array[byte_no] = s->array[byte_no] | 1 << bit;
        s->size++;
    }
}


// Note: More effective implementations are possible, but this is
// okay for this assignment.
set *set_union(const set *const s1, const set *const s2)
{
    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) || set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}


set *set_intersection(const set *const s1, const set *const s2)
{
	set *s = set_empty();

	for (int i = 0 ; i < s1->capacity && i < s2->capacity ; i++) {
		if (set_member_of(i, s1) && set_member_of(i, s2)) {
			set_insert(i, s);
		}
	}

	return s;
}


set *set_difference(const set *const s1, const set *const s2)
{
	set *s = set_empty();

	for (int i = 0 ; i < s1->capacity ; i++) {
		if (set_member_of(i, s1) && !set_member_of(i, s2)) {
			set_insert(i, s);
		}
	}

	return s;
}


bool set_is_empty(const set *const s)
{
	return s->size == 0;
}


bool set_member_of(const int value, const set *const s)
{
    int bit_in_array = value; // To make the code easier to read

    if (bit_in_array >= s->capacity) {
        return false;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    char the_byte = s->array[byte_no];

    return the_byte & 1 << bit;
}


int set_choose(const set *const s)
{
	for (int i = 0 ; i < s->capacity ; i++) {
		if (set_member_of(i, s)) {
			return i;
		}
	}

	return -1;
}


void set_remove(const int value, set *const s)
{
	if (set_member_of(value, s)) {
		int bit_in_array = value; // To make the code easier to read
		int byte_no = bit_in_array / 8;
		int bit = 7 - bit_in_array % 8;
		s->array[byte_no] = s->array[byte_no] & ~(1 << bit);
		s->size--;
	}
}


bool set_equal(const set *const s1, const set *const s2)
{
	return set_subset(s1, s2) && set_subset(s2, s1);
}


bool set_subset(const set *const s1, const set *const s2)
{
	for (int i = 0 ; i < s1->capacity ; i++) {
		if (set_member_of(i, s1) && !set_member_of(i, s2)) {
			return false;
		}
	}

	return true;
}


int set_size(const set *const s)
{
	return s->size;
}


int *set_get_values(const set *const s)
{
	int *values = malloc(s->size * sizeof(int));
	int j = 0;

	for (int i = 0 ; i < s->capacity ; i++) {
		if (set_member_of(i, s)) {
			values[j] = i;
			j++;
		}
	}

	return values;
}


void set_destroy(set *s)
{
	free(s->array);
	free(s);
}