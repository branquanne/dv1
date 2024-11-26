#include "table.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

static void populate_table(Table *table) {
  for (int n = 51; n <= 60; n++) {
    table_insert(table, n, -n);
  }

  for (int n = 141; n <= 160; n++) {
    table_insert(table, n, n * n);
  }
}

static bool verify_pairs(Table *table) {
  int count = 0;
  for (int n = 51; n <= 60; n++) {
    int value;
    int key = n;
    if (table_lookup(table, key, &value) && value == -n) {
      printf("Key %d has value %d\n", key, value);
      count++;
    } else {
      return false;
    }
  }

  for (int n = 141; n <= 160; n++) {
    int value;
    int key = n;
    if (table_lookup(table, key, &value) && value == n * n) {
      printf(ANSI_COLOR_GREEN "Key %d has value %d\n" ANSI_COLOR_RESET, key,
             value);
      count++;
    }
  }
  if (count == 30) {
    return true;
  }
  return false;
}

static bool verify_nonpairs(Table *table) {
  int count = 0;
  for (int n = 1; n <= 200; n++) {
    int value = 0;
    int key = n;
    if (!table_lookup(table, key, &value)) {
      printf(ANSI_COLOR_RED "Key %d has no value\n" ANSI_COLOR_RESET, key);
      count++;
    } else {
      printf("Key %d has value %d\n", key, value);
    }
  }
  if (count == 170) {
    return true;
  }
  return false;
}

int main(void) {
  Table *tab = table_create(100);

  populate_table(tab);

  bool pairs_are_correct = verify_pairs(tab);
  bool table_is_correct = verify_nonpairs(tab);

  printf("Test the presence of added key/value pairs ... %s\n",
         pairs_are_correct ? "PASS" : "FAIL");
  printf("Test the presence of non-added keys ... %s\n",
         table_is_correct ? "PASS" : "FAIL");

  table_destroy(tab);

  return 0;
}
