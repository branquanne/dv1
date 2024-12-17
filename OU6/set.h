#ifndef SET_H
#define SET_H

#include <stdbool.h>


// The type for the set.
typedef struct set set;

// Creates a new empty set.
set *set_empty();

// Creates a new set with a single member (value).
set *set_single(const int value);

// Inserts the value in the set.
void set_insert(const int value, set *s);

// Returns a new set that is the union of the two sets.
set *set_union(const set *const s1, const set *const s2);

// Returns a new set that is the intersection of the two sets.
set *set_intersection(const set *const s1, const set *const s2);

// Returns a new set that is the difference of the two sets (s1 \ s2).
set *set_difference(const set *const s1, const set *const s2);

// Checks if the set is empty.
bool set_is_empty(const set *const s);

// Checks if the value is a member of the set.
bool set_member_of(const int value, const set *const s);

// Returns a random member of the set (without removing it).
int set_choose(const set *const s);

// Removes the value from the set.
void set_remove(const int value, set *const s);

// Checks if the two sets are equal.
bool set_equal(const set *const s1, const set *const s2);

// Checks if the first set is a subset of the second set.
bool set_subset(const set *const s1, const set *const s2);

// Returns an array with all the values in the set.
int *set_get_values(const set *const s);

// Returns the number of elements in the set.
int set_size(const set *const s);

// Destroys the set.
void set_destroy(set *s);


#endif /* SET_H */