#include <stdio.h>
#include <time.h>

#define RAND_MAX 10
#define RAND_MIN 0
#define MAX_TRYS 3

int main(void) {
	srand(time(0));
	rand();
	int randomNumber = ((int)10.0*rand()) % (((RAND_MAX+1) - RAND_MIN) + RAND_MIN);
	
	printf("Which number are we looking for? (%d - %d)\n-> ", RAND_MIN, RAND_MAX);
	int numberInput = -1;

	int trys = 0;
	while (++trys <= MAX_TRYS) {
		scanf("%d", &numberInput);
		if (randomNumber > numberInput)
			printf("That's not enough!\n-> ");
		else if (randomNumber < numberInput)
			printf("That's too much!\n-> ");
		else {
			printf("That's the right number!!\n");
			system("pause");
			return 0;
		}
	}

	printf("We're out of trys :'( BYEEE\n");
	system("pause");
	return 0;
}