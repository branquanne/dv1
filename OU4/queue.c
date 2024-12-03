#include "queue.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

struct queue {
  List *list;
};

static char *clone_string(const char *in) {
  size_t len = strlen(in);
  char *out = calloc(len + 1, sizeof(char));

  strncpy(out, in, len);

  return out;
}

Queue *queue_create(void) {}

void queue_destroy(Queue *q) {}

void queue_enqueue(Queue *q, const char *value) {}

char *queue_dequeue(Queue *q) {}

bool queue_is_empty(const Queue *q) {}
