#include <stdio.h>

#define ARRSIZE 24
char my_bitvec[ARRSIZE / 8];

int get(char *bitvec, int index);
int getInvalid(char *bitvec, int index);
void set(char *bitvec, int index);
void setInvalid(char *bitvec, int index);
void reset(char *bitvec, int index);

int main(void) {

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
	reset(my_bitvec, 7);
	reset(my_bitvec, 23);
	reset(my_bitvec, 24);
	for (int i = 1; i <= 24; i++)
		printf("%d ", get(my_bitvec, i));

	printf("\n");
	setInvalid(my_bitvec, 7);
	for (int i = 1; i <= 24; i++)
		printf("%d ", getInvalid(my_bitvec, i));

	printf("\n");

	system("pause");
	return 0;
}

void setInvalid(char *bitvec, int index) {
	*(bitvec) |= (0x01 << index);
}

int getInvalid(char *bitvec, int index) {
	return ((0x01 << index) & *(bitvec)) > 0x00;
}


int get(char *bitvec, int index) {
	int bitIndex = index / 8;
	int moveIndex = index - bitIndex * 8;
	return ((0x01 << moveIndex) & *(bitvec + bitIndex)) > 0x00;
}

void set(char *bitvec, int index) {
	int bitIndex = index / 8;
	int moveIndex = index - bitIndex * 8;
	*(bitvec + bitIndex) |= (0x01 << moveIndex);
}

void reset(char *bitvec, int index) {
	int bitIndex = index / 8;
	int moveIndex = index - bitIndex * 8;
	*(bitvec + bitIndex) &= ~(0x01 << moveIndex);
}