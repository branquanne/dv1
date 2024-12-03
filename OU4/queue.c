#include "queue.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

struct queue {
    List *list;
};

static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));

    strncpy(out, in, len);

    return out;
}

Queue *queue_create(void)
{
    Queue *q = malloc(sizeof(Queue));
    q->list = list_create();
    return q;
}

void queue_destroy(Queue *q)
{
    list_destroy(q->list);
    free(q);
}

void queue_enqueue(Queue *q, const char *value)
{
    list_insert(list_end(q->list), clone_string(value));
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
