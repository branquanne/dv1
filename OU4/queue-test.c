#include "queue.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // Create an empty queue.
  Queue *q = queue_create();

  // Add the values A, B, ..., Z to the queue.
  char str[] = "A";
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    str[0] = ch;
    queue_enqueue(q, str);
  }

  // Verify the values in the queue.
  bool ok = true;
  for (char ch = 'A'; ch <= 'Z'; ch++) {
    str[0] = ch;
    char *str2 = queue_dequeue(q);
    if (strcmp(str, str2) != 0) {
      ok = false;
    }
    free(str2);
  }

  // Verify that the queue is empty.
  if (!queue_is_empty(q)) {
    ok = false;
  }

  // Print the result of the test.
  printf("Test the functioning of the queue ... %s\n", ok ? "PASS" : "FAIL");

  // Clean up.
  queue_destroy(q);

  return 0;
}
