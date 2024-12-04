#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
/**
 * @defgroup queue_h QUEUE_H
 *
 * @brief The Queue module is a simple queue implementation.
 *
 * The queue is a data structure that allows elements to be inserted and removed in a first-in-first-out
 * (FIFO) order. This means that the first element that was inserted into the queue
 * is the first one to be removed.
 *
 * @author Bran Mjöberg Quanne
 * @since 2024-12-03
 * @{
 */

/**
 * @brief The type for a queue.
 *
 * @note The implementation of the queue is hidden from the user of the module and has to be
 * defined in the implementation file.
 */
typedef struct queue Queue;

/**
 * @brief Create an empty queue.
 *
 * This function creates a new queue and allocates memory for it.
 *
 * @param None.
 *
 * @return A pointer to the newly created queue.
 *
 * @note The caller is responsible for deallocating the memory used by the queue. This can be done using queue_destroy().
 * @note The function does not check if the memory allocation is successful and thus it may result in an undefined behaviour.
 */
Queue *queue_create(void);

/**
 * @brief Destroy the queue.
 *
 * This function deallocates the memory used by the queue.
 *
 * @param q A pointer to the queue to be destroyed.
 *
 * @return None.
 *
 * @note The function does not check if the queue exists and thus it may result in an undefined behaviour.
 */
void queue_destroy(Queue *q);

/**
 * @brief Add a value to the tail of the queue.
 *
 * This function adds a value to the tail of the queue.
 *
 * @param q A pointer to the queue.
 * @param value The value to be added to the queue.
 *
 * @return None.
 *
 * @note This function does not check if the memory allocation is successful and
 * thus it may result in an undefined behaviour.
 * @note This function does not check if the value is a valid string and thus it may result in an undefined behaviour.
 *
 */
void queue_enqueue(Queue *q, const char *value);

/**
 * @brief Remove the value at the head of the queue.
 *
 * This function removes the value at the head of the queue.
 *
 * @param q A pointer to the queue.
 *
 * @return A pointer to the value at the head of the queue.
 *
 * @note This function does not check if the queue is empty and thus it may result in an undefined behaviour.
 */
char *queue_dequeue(Queue *q);

/**
 * @brief Check if the queue is empty.
 *
 * This function checks if the queue is empty.
 *
 * @param q A pointer to the queue.
 *
 * @return True if the queue is empty, otherwise false.
 *
 * @note This function does not check if the queue exists and thus it may result
 * in an undefined behaviour.
 */
bool queue_is_empty(const Queue *q);
/**
 * @}
 */
#endif /* QUEUE_H */
