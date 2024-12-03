#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// The type for the queue.
typedef struct queue Queue;

// Create and return an empty queue.
Queue *queue_create(void);

// Destroy the queue.
void queue_destroy(Queue *q);

// Add a value to the tail of the queue.
// The value is copied to dynamically allocated memory.
void queue_enqueue(Queue *q, const char *value);

// Remove the value at the head of the queue.
// The caller is responsible for deallocating the returned pointer.
char *queue_dequeue(Queue *q);

// Check if the queue is empty.
bool queue_is_empty(const Queue *q);

#endif /* QUEUE_H */
