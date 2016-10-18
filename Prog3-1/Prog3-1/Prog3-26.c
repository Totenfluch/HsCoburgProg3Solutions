#include <stdio.h>
#include <time.h>

int main(void) {
	int rCounter;
	FILE *rf;
	rf = fopen("memo.txt", "r");
	if (rf) {
		while ((rCounter = getc(rf)) != EOF)
			putchar(rCounter);
		fclose(rf);
	}

	char text[512];
	while (1) {
		printf("Please enter some Text('.' to exit): \n-> ");
		fflush(stdin);
		scanf_s(" %512[0-9a-zA-Z.,-_*'?!§$&/()=°^ ]", &text, 512);

		printf("\n");
		if (text[0] == '.')
			break;

		time_t t;
		time(&t);

		printf("[%.24s] %s\n", ctime(&t), &text);

		FILE *fp;
		fp = fopen("memo.txt", "a");
		if (fp == NULL)
			exit(-1);
		fprintf(fp, "[%.24s] %s\n", ctime(&t), &text);
		fclose(fp);
		strcpy(text, "");
	}

	system("pause");
	return 0;
}