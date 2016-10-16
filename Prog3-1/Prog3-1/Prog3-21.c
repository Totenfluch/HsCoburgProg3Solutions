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
	int maxLen = strlaenge(str1);
	int findLen = strlaenge(str2);
	int foundLen = 0;
	for (int i = 0; i < maxLen; i++) {
		if (str1[i] == str2[foundLen])
			foundLen++;
		else
			foundLen = 0;
		if (foundLen == findLen)
			return (i+1) - foundLen;
	}
	return -1;
}

int strlaenge(const char* str) {
	int len = 0;
	int i = 0;
	while (str[i++] != '\0')
		len++;
	return len;
}