#include <stdio.h>

int main(void) {
	printf("Please enter some Text:\n-> ");
	char text[64];
	scanf_s("%64[0-9a-zA-Z ]", &text, 64);
	printf("Please enter a Letter:\n-> ");
	char checkChar;
	scanf_s(" %c", &checkChar, 1);
	int count = 0;
	for (int i = 0; i < 512; i++)
		if ((text[i] == checkChar) && text[i] != '\0')
			count++;
	printf("%c is %d times in %s\n", checkChar, count, &text);
	system("pause");
	return 0;
}