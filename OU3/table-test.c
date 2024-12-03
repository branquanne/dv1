#include "table.h"
#include <stdio.h>

/* Description:   This test program inserts 30 key/value pairs into a table,
 *                then verifies that the pairs are present. It also verifies
 *                that the table does not contain any key/value pairs that were
 *                not inserted.
 *
 *                The test program is successful if it prints "PASS" for both
 *                tests. The test program is unsuccessful if it prints "FAIL"
 *                for either test.
 *
 * Author:        Bran Quanne
 * Date:          2024-12-01
 * File:          table-test.c
 */

/* --- The following functions are not declared in table.h ---*/

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
      count++;
    } else {
      return false;
    }
  }

  for (int n = 141; n <= 160; n++) {
    int value;
    int key = n;
    if (table_lookup(table, key, &value) && value == n * n) {
      count++;
    } else {
      return false;
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
      count++;
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
