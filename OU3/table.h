#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

// The type for a bucket.
struct bucket {
    int key;
    int value;
    bool used;
};

// The type for the table.
typedef struct table {
    // The number of buckets.
    int capacity;
    // The bucket array.
    struct bucket *buckets;
} Table;

// Create an empty table.
Table *table_create(int capacity);

// Destroy the table.
void table_destroy(Table *tab);

// Lookup the value for a key and return false if the key is not found.
bool table_lookup(Table *tab, int key, int *value);

// Insert a key/value pair and overwrite the value if the key exists.
void table_insert(Table *tab, int key, int value);

#endif /* TABLE_H */