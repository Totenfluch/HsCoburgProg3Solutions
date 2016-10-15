#include <stdio.h>

#define SWAP(a, b) {int c = a; a = b; b = c;}

int main(void) {
	int meinArray[5];
	printf("Bitte 5 Zahlen eingeben: \n");
	scanf("%i %i %i %i %i", &meinArray[0], &meinArray[1], &meinArray[2], &meinArray[3], &meinArray[4]);
	for (int i = 0; i < 5; i++) {
		for (int x = 0; x < 5; x++) {
			if (meinArray[i] > meinArray[x])
				SWAP(meinArray[i], meinArray[x]);
		}
	}

	int summed = 0;
	for (int i = 0; i < 5; i++) {
		//printf("%d ", meinArray[i]);
		summed += meinArray[i];
	}
	printf("\n%d", (summed / 5));

	system("pause");
	return 0;
}