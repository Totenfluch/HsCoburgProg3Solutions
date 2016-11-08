#include <stdio.h>
#include <stdlib.h>

int* selectMask(int* a, int size, int maske);

int main(void) {
	int p = 0;
	int* x = &p;
	*x |= (1 << 2);
	*x |= (1 << 4);
	*x |= (1 << 6);

	int maske = 0;
	maske |= (1 << 4);

	printf("%d %d\n", *x, maske);

	int* result = selectMaskSingle(x, sizeof(x), maske);
	printf("%d %d %d\n", *x, maske, *result);
	system("pause");

	system("pause");
	free(result);
	return 0;
}

// Für ein Feld
int* selectMaskSingle(int* a, int size, int maske) {
	int* returnValue = (int *)calloc(sizeof(a), sizeof(a));
	for (int i = 1; i <= size * 8; i++) {
		if (((*a & (1 << i)) > 0) && ((maske & (1 << i)) > 0)) {
			*returnValue |= 1 << i;
			*a &= ~(1 << i);
		}
	}

	return returnValue;
}


// Nach Aufgabenstellung
int* selectMask(int* a, int n, int mask, int* sz) {
	int i, count;
	int* res;

	for (i = 0, count = 0; i < n; i++)
		if ((a[i] & mask) == mask)
			count++;

		*sz = count;
		res = (int*)calloc(count, sizeof(int));
		for (i = 0, count = 0; i < n; i++)
			if((a[i] & mask) == mask)
				res[count++] = a[i] & ~mask;

	return res
}
