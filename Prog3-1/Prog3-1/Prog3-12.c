#include <stdio.h>

unsigned char rotate(unsigned char c, int n);
int getBitAtPosition(char c, int pos);
void printCharAsBit(char c);

int main(void) {
	unsigned char n = 154;

	printCharAsBit(n);
	printf("\n%d\n", n);
	n = rotate(n, 1);
	printCharAsBit(n);
	printf("\n%d\n", n);

	system("pause");
	return 0;
}

unsigned char rotate(unsigned char c, int n) {
	while (--n >= 0) {
		int x = c & (1 << 7);
		c <<= 1;
		c |= ((x & 1 << 7) > 0);
	}
	return c;
}

int getBitAtPosition(char c, int pos) {
	return ((1 << pos) & c) > 0;
}

void printCharAsBit(char c) {
	for (int i = 7; i >= 0; i--) {
		printf("%i ", getBitAtPosition(c, i));
	}
}
