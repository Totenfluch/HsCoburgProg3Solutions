#include <stdio.h>

int substr(const char* str1, const char* str2);
int strlaenge(const char* str);

int main(void) {
	char string1[] = "Wir sind kluge Studenten";
	char string2[] = "kluge Studenten sind wir";
	char find1[] = "kluge";
	char find2[] = "Studenten";
	printf("%s\n%s\nPos: %d\nLen: %d\n\n\n", string1, find1, substr(string1, find1), strlaenge(string1));
	printf("%s\n%s\nPos: %d\nLen: %d\n\n\n", string2, find1, substr(string2, find1), strlaenge(string1));
	printf("%s\n%s\nPos: %d\nLen: %d\n\n\n", string2, find2, substr(string2, find2), strlaenge(string1));
	system("pause");
	return 0;
}

int substr(const char* str1, const char* str2) {
	for (int i = 0, foundLen = 0; i < strlaenge(str1); i++) {
		if (str1[i] == str2[foundLen])
			foundLen++;
		else
			foundLen = 0;
		if (foundLen == strlaenge(str2))
			return (i+1) - foundLen;
	}
	return -1;
}

int strlaenge(const char* str) {
	int len = 0;
	while (str[len++] != '\0');
	return len-1;
}