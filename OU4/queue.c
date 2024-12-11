#include "queue.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

/*
 * File :       queue.c
 *
 * Description: This file contains the implementation of the queue module.
 *              The queue is a data structure that allows elements to be inserted and removed in a first-in-first-out (FIFO) order.
 *              This means that the first element that was inserted into the queue is the first one to be removed.
 *
 * Author:      Bran Mjöberg Quanne
 *
 * Date:        2024-12-08
 */

/* --- The following function is not declared in queue.h ---*/

/*
 * Description: Clones a string and allocates memory for the new string.
 *
 * Input:       A string.
 *
 * Output:      A pointer to a new string.
 */
static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));
    strncpy(out, in, len);
    return out;
}

/* --- The following functions are declared in queue.h --- */

/*
 * Description: The structure used to represent a queue. The queue is implemented using a list.
 */
struct queue {
    List *list;
};

Queue *queue_create(void)
{
    Queue *q = malloc(sizeof(Queue));
    q->list = list_create();
    return q;
}

void queue_destroy(Queue *q)
{
    while (!list_is_empty(q->list)) {
        char *value = queue_dequeue(q);
        free(value);
    }
    list_destroy(q->list);
    free(q);
}

void queue_enqueue(Queue *q, const char *value)
{
    list_insert(list_end(q->list), value);
}

char *queue_dequeue(Queue *q)
{
    char *value = clone_string(list_inspect(list_first(q->list)));
    list_remove(list_first(q->list));
    return value;
}

bool queue_is_empty(const Queue *q)
{
    return list_is_empty(q->list);
}
