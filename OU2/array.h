#ifndef ARRAY_H
#define ARRAY_H

/**
 * @defgroup ARRAY_H array.h
 *
 * @brief Declarations used to represent the abstract data type Array.
 *
 * A module that contains the declarations of the struct Array
 * and functions used to create and manipulate a 2D array.
 * The module declarations are used by the files array.c and main.c.
 *
 * @author Bran Mjöberg Quanne
 *
 * @since 2024-12-16
 * @{
 */

/**
 * @brief The type for a 2D array.
 *
 * The type for a 2D array. The struct contains the number of rows and columns
 * and a pointer to the array.
 *
 */
typedef struct array {
    int n1;    /**< The number of rows. */
    int n2;    /**< The number of columns. */
    int *data; /**< A pointer to the array. */
} Array;

/**
 * @brief Create and return a zero array of a user-specified size.
 *
 * Create and return a zero array of size n1 rows by n2 columns. The function also
 * allocates memory for the array.
 *
 * @param n1 The number of rows.
 *
 * @param n2 The number of columns.
 *
 * @return A pointer to the created array.
 *
 * @see array_destroy()
 *
 * @note The function does not check if the memory allocation is successful.
 * @note User will have to manually call array_destroy() in order to free the memory allocated for the array.
 */
Array *array_create(int n1, int n2);

/**
 * @brief Destroy an array.
 *
 * The function frees the memory allocated for the array.
 *
 * @param arr A pointer to the array to destroy.
 *
 * @return None.
 *
 * @see array_create()
 *
 * @note The function does not check if the array exists nor does it check if the pointer is empty and thus it may result in an undefined behaviour.
 */
void array_destroy(Array *arr);

/**
 * @brief Get the number of rows.
 *
 * Get the number of rows in the array.
 *
 * @param arr A pointer to the array.
 *
 * @return The number of rows.
 *
 * @see array_columns()
 */
int array_rows(const Array *arr);

/**
 * @brief Get the number of columns.
 *
 * Get the number of columns in the array.
 *
 * @param arr A pointer to the array.
 *
 * @return The number of columns.
 *
 * @see array_rows()
 */
int array_columns(const Array *arr);

/**
 * @brief Return the value at a user-specified position in the array.
 *
 * Return the value at specific row and column in the array (zero-based indexing).
 *
 * @param arr A pointer to the array.
 *
 * @param i1 The row index.
 *
 * @param i2 The column index.
 *
 * @return The value at the specified position.
 *
 * @note The function does not check if the indices are within bounds and thus it may result in an undefined behaviour.
 */
int array_get(const Array *arr, int i1, int i2);

/**
 * @brief Set the value at a user-specified position in the array.
 *
 * Set the value at specific row and column in the array (zero-based indexing).
 *
 * @param arr A pointer to the array.
 *
 * @param i1 The row index.
 *
 * @param i2 The column index.
 *
 * @param value The value to set.
 *
 * @return None.
 *
 * @note The function does not check if the indices are within bounds and thus it may result in an undefined behaviour.
 */
void array_set(Array *arr, int i1, int i2, int value);
/**
 * @}
 */
#endif /* ARRAY_H */
