#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

/**
 * @defgroup table_h TABLE_H
 *
 * @brief The Table module is a simple hash table implementation.
 *
 * The Table module is a simple hash table implementation. The table is an array
 * of buckets, where each bucket contains a key, a value.
 *
 * @author  Bran Quanne
 * @since    2024-11-27
 * @{
 * */

/**
 * @brief The type for a bucket.
 *
 * The type for a bucket. The struct contains a key, a value, and a boolean flag
 * to indicate if the bucket is used.
 */
struct bucket {
  int key;   /**< The key. */
  int value; /**< The value. */
  bool used; /**< A boolean flag to indicate if the bucket is used. */
};

/**
 * @brief The type for the table.
 *
 * The type for the table. The struct contains the number of buckets and a
 * pointer to the bucket array.
 */
typedef struct table {
  int capacity;           /**< The number of buckets. */
  struct bucket *buckets; /**< A pointer to the bucket array. */
} Table;

/**
 * @brief Create an empty table.
 *
 * Create and return an empty table of a user-specified capacity. The function
 * also allocates memory for the table.
 *
 * @param capacity The number of buckets.
 *
 * @return A pointer to the created table.
 *
 * @see table_destroy()
 *
 * @note The function does not check if the memory allocation is successful nor
 * does it check for non-positive capacity and thus it may result in an
 * undefined behaviour.
 *
 * @note User will have to manually call table_destroy() in order to free the
 * memory allocated for the table.
 */
Table *table_create(int capacity);

/**
 * @brief Destroy the table.
 *
 * The function frees the memory allocated for the table.
 *
 * @param tab A pointer to the table to destroy.
 *
 * @return None.
 *
 * @see table_create()
 *
 * @note The function does not check if the table exists and thus it may result
 * in an undefined behaviour.
 */
void table_destroy(Table *tab);

/**
 * @brief Lookup the value for a key.
 *
 * Lookup the value for a key in a table and returns true if the key is found
 * and false if the key is not found.
 *
 * @param tab A pointer to the table.
 *
 * @param key The key to lookup.
 *
 * @param value A pointer to the value to return.
 *
 * @return True if the key is found, false otherwise.
 *
 * @note The function does not check if the table exists and thus it may result
 * in an undefined behaviour.
 */
bool table_lookup(Table *tab, int key, int *value);

/**
 * @brief Insert a key/value pair into a table.
 *
 * Insert a key/value pair into a table and overwrite the value if the key
 * exists.
 *
 * @param tab A pointer to the table.
 *
 * @param key The key to insert.
 *
 * @param value The value to insert.
 *
 * @return None.
 *
 * @note The function does not check if the table exists and thus it may result
 * in an undefined behaviour.
 */
void table_insert(Table *tab, int key, int value);
/**
 * @}
 * */
#endif /* TABLE_H */
