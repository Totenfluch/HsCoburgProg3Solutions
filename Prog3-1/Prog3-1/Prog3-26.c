#include <stdio.h>
#include <time.h>

int main(void) {
	printf("Please enter some Text: \n-> ");
	char text[512];
	scanf_s("%512[0-9a-zA-Z ]", &text, 512);

	time_t t;
	time(&t);
	
	printf("[%.24s] %s\n", ctime(&t), &text);


	FILE *fp;
	fp = fopen("memo.txt", "w");
	if (fp == NULL)
		exit(-1);
	fprintf(fp, "[%.24s] %s\n", ctime(&t), &text);
	fclose(fp);

	system("pause");
	return 0;
}