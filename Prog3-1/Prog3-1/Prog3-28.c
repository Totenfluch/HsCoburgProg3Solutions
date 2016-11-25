#include <stdio.h>


union ieee754 {
	int i;
	float f;
} gleitkommazahl;

int main(void) {
	float inputFloat;
	unsigned char* cp;
	printf("Bitte eine Float eingeben:\n");
	scanf_s("%f", &inputFloat);
	cp = (unsigned char*) &inputFloat;
	printf("%2X %2X %2X %2X\n", cp[0], cp[1], cp[2], cp[3]);

	gleitkommazahl.f = inputFloat;
	printf("%X\n", gleitkommazahl.i);

	system("pause");


	return 0;
}