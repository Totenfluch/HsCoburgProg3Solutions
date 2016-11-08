#include <stdio.h>

void strcpy1(char * s, char * t);
void strcpy2(char * s, char * t);

int main(void) {
	char dest1[64];
	char string1[] = "Hallo meine Studenten!";
	char dest2[64];
	char string2[] = "Hallo meine lieben Studenten!";
	strcpy1(dest1, string1);
	strcpy2(dest2, string2);
	printf("%s\n%s\n%s\n%s\n", dest1, string1, dest2, string2);
	printf("Test1: %d  - Test2: %d | 0 -> Success\n", strcmp(dest1, string1), strcmp(dest2, string2));
	system("pause");
	return 0;
}

void strcpy1(char * s, char * t)
{
	int i = 0;
	while (s[i] = t[i])
		i++;
}

void strcpy2(char * s, char * t)
{
	while (*s = *t)
	{
		s++;
		t++;
	}
}