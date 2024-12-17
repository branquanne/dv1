#include <stdio.h>
#include "set.h"

struct set {
    int capacity;
    int size;
    char *array;
};

int main(void)
{
	set *s1 = set_single(1);
	set *s2 = set_single(2);
	set *s3 = set_union(s1, s2);
	set *s4 = set_intersection(s1, s2);
	set *s5 = set_difference(s1, s2);

	printf("s1: ");
	for (int i = 0 ; i < s1->capacity ; i++) {
		if (set_member_of(i, s1)) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("s2: ");
	for (int i = 0 ; i < s2->capacity ; i++) {
		if (set_member_of(i, s2)) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("s3: ");
	for (int i = 0 ; i < s3->capacity ; i++) {
		if (set_member_of(i, s3)) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("s4: ");
	for (int i = 0 ; i < s4->capacity ; i++) {
		if (set_member_of(i, s4)) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("s5: ");
	for (int i = 0 ; i < s5->capacity ; i++) {
		if (set_member_of(i, s5)) {
			printf("%d ", i);
		}
	}
	printf("\n");

	set_destroy(s1);
	set_destroy(s2);
	set_destroy(s3);
	set_destroy(s4);
	set_destroy(s5);

	return 0;
}