#include <stdio.h>

int main(void) {
	int day = -1, month = -1, year = -1;
	printf("Please enter a day DD.MMM.YYYY\n-> ");
	scanf("%d.%d.%d", &day, &month, &year);

	// Error prevention
	day %= 32;
	month %= 13;

	if (month == 1) {
		month = 13;
		year--;
	} else if (month == 2) {
		month = 14;
		year--;
	}

	int part1Year = year / 100;
	int part2Year = year % 100;

	int result = (day + (((month + 1) * 26) / 10) + (5 * part2Year) / 4 + part1Year / 4 - (2 * part1Year) - 1) % 7;
	while (result < 0)
		result += 7;


	printf("The %02d.%02d.%04d was a ", day, month, year);

	switch (result) {
	case 0: printf("sunday"); break;
	case 1: printf("monday"); break;
	case 2: printf("tuesday"); break;
	case 3: printf("wednesday"); break;
	case 4: printf("thursday"); break;
	case 5: printf("friday"); break;
	case 6: printf("saturday"); break;
	}

	printf("\n\n");

	system("pause");
	return 0;
}