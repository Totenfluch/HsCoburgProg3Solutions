#include <stdio.h>



int main(void) {
	for (int i = 66; i < 99; i++)
		printf("%s", &i);
	printf("\n");
	system("PAUSE");
	return 0;
}