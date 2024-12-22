#ifndef SET_H
#define SET_H
#include <stdbool.h>

/**
 * @defgroup set_h SET_H
 *
 * @brief A module for creating and manipulating sets.
 *
 * @details This module provides a set data structure and functions for creating and manipulating sets.
 *
 * @author Bran Mjöberg Quanne
 *
 * @since 2024-12-21
 *
 * @{
 */

/**
 * @brief The type for the set.
 *
 * The implementation of the set is hidden from the user and needs to be implemented in the implementation file.
 */
typedef struct set set;

/**
 * @brief Creates a new empty set.
 *
 * This function creates a new empty set and allocates memory for it.
 *
 * @return A pointer to the new empty set.
 *
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling set_destroy().
 *
 * @see set_destroy()
 */
set *set_empty();

/**
 * @brief Creates a new set with a single element.
 *
 * This function creates a new set with a single member element and allocates memory for it.
 *
 * @param value The value to be inserted into the set.
 *
 * @return A pointer to the new set with a single element.
 *
 * @note Usage may result in undefined behavior if the value is not within the range of the set.
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling set_destroy().
 *
 * @see set_destroy()
 */
set *set_single(const int value);

/**
 * @brief Inserts a value into the set.
 *
 * This function inserts a value into the set.
 *
 * @param value The value to be inserted into the set.
 * @param s A pointer to the set.
 *
 * @note Usage may result in undefined behavior if the value is not within the range of the set or if the set does not exist.
 *
 * @see set_remove()
 */
void set_insert(const int value, set *s);

/**
 * @brief Returns a new set that is the union of two sets.
 *
 * This function returns a new set that is the union of two sets.
 *
 * @param s1 A pointer to the first set.
 * @param s2 A pointer to the second set.
 *
 * @return A pointer to the new set that is the union of the two sets.
 *
 * @note Usage may result in undefined behavior if the sets do not exist.
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling set_destroy().
 *
 * @see set_intersection()
 * @see set_difference()
 */
set *set_union(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the intersection of two sets.
 *
 * This function returns a new set that is the intersection of two sets.
 *
 * @param s1 A pointer to the first set.
 * @param s2 A pointer to the second set.
 *
 * @return A pointer to the new set that is the intersection of the two sets.
 *
 * @note Usage may result in undefined behavior if the sets do not exist.
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling set_destroy().
 *
 * @see set_union()
 * @see set_difference()
 */
set *set_intersection(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the difference of two sets.
 *
 * This function returns a new set that is the difference of two sets.
 *
 * @param s1 A pointer to the first set.
 * @param s2 A pointer to the second set.
 *
 * @return A pointer to the new set that is the difference of the two sets.
 *
 * @note Usage may result in undefined behavior if the sets do not exist.
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling set_destroy().
 *
 * @see set_union()
 * @see set_intersection()
 */
set *set_difference(const set *const s1, const set *const s2);

/**
 * @brief Checks if the set is empty.
 *
 * This function checks if the set is empty.
 *
 * @param s A pointer to the set.
 *
 * @return True if the set is empty, otherwise false.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 */
bool set_is_empty(const set *const s);

/**
 * @brief Checks if the value is a member of the set.
 *
 * This function checks if the value is a member of the set.
 *
 * @param value The value to be checked.
 * @param s A pointer to the set.
 *
 * @return True if the value is a member of the set, otherwise false.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 */
bool set_member_of(const int value, const set *const s);

/**
 * @brief Returns the first member of the set.
 *
 * This function returns the first valid member of the set.
 *
 * @param s A pointer to the set.
 *
 * @return A random member of the set or -1 if the set is empty.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 */
int set_choose(const set *const s);

/**
 * @brief Removes a value from the set.
 *
 * This function removes a value from the set.
 *
 * @param value The value to be removed.
 * @param s A pointer to the set.
 *
 * @note Usage may result in undefined behavior if the value is not within the range of the set or if the set does not exist.
 *
 * @see set_insert()
 */
void set_remove(const int value, set *const s);

/**
 * @brief Checks if two sets are equal.
 *
 * This function checks if two sets are equal.
 *
 * @param s1 A pointer to the first set.
 * @param s2 A pointer to the second set.
 *
 * @return True if the sets are equal, otherwise false.
 *
 * @note Usage may result in undefined behavior if the sets do not exist.
 */
bool set_equal(const set *const s1, const set *const s2);

/**
 * @brief Checks if the first set is a subset of the second set.
 *
 * This function checks if the first set is a subset of the second set.
 *
 * @param s1 A pointer to the first set.
 * @param s2 A pointer to the second set.
 *
 * @return True if the first set is a subset of the second set, otherwise false.
 *
 * @note Usage may result in undefined behavior if the sets do not exist.
 */
bool set_subset(const set *const s1, const set *const s2);

/**
 * @brief Returns an array with all the values in the set.
 *
 * This function returns an array with all the values in the set.
 *
 * @param s A pointer to the set.
 *
 * @return An array with all the values in the set.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 * @note The user is responsible for freeing the memory allocated by this function. This can be done by calling free().
 */
int *set_get_values(const set *const s);

/**
 * @brief Returns the number of elements in the set.
 *
 * This function returns the number of elements in the set.
 *
 * @param s A pointer to the set.
 *
 * @return The number of elements in the set.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 */
int set_size(const set *const s);

/**
 * @brief Destroys the set.
 *
 * This function destroys the set and frees the memory allocated for it.
 *
 * @param s A pointer to the set.
 *
 * @note Usage may result in undefined behavior if the set does not exist.
 *
 * @see set_empty() & set_single()
 */
void set_destroy(set *s);

/**
 * @}
 */
#endif /* SET_H */