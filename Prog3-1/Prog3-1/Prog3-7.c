#include <stdio.h>

int main(void) {
	char inseln[][10] = { "Bermudas", "Fidschi", "Komoren", "Kuba"};
	int y = 0;
	int ref = 0;
	int index[] = { 1, 3, 0, 2 };
	while (y < 4) {
		ref = index[y];
		printf("Insel: ");
		printf("%s\n", inseln[ref]);
		y = y + 1;
	}

	system("PAUSE");
	return 0;
}