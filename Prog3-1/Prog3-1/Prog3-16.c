#include <stdio.h>

#define ARRSIZE 24
char my_bitvec[ARRSIZE / 8];

int get(char *bitvec, int index) {
	return ((0x01 << index) & *bitvec) > 0x00;
}

void set(char *bitvec, int index) {
	*bitvec |= (0x01 << index);
}

void reset(char *bitvec, int index) {
	*bitvec &= ~(0x01 << index);
}

int main(void) {

	set(my_bitvec, 0);
	set(my_bitvec, 1);
	set(my_bitvec, 6);
	set(my_bitvec, 7);
	set(my_bitvec, 23);
	set(my_bitvec, 24);
	for (int i = 1; i <= 24; i++)
		printf("%d ", get(my_bitvec, i));

	printf("\n");

	reset(my_bitvec, 1);
	reset(my_bitvec, 6);
	reset(my_bitvec, 23);
	reset(my_bitvec, 24);
	for (int i = 1; i <= 24; i++)
		printf("%d ", get(my_bitvec, i));

	printf("\n");

	system("pause");
	return 0;
}