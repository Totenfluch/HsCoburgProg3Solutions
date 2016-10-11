#include <stdio.h>
#include <time.h>

#define RAND_MAX 1

int main(void) {
	srand(time(0));
	int z = (int)(10.0*rand() / (RAND_MAX + 1.0));
	printf("Welche Zahl suchen wir\n");
	int eingabe = -1;
	scanf("%i", &eingabe);
	while (z != eingabe) {
		if (z < eingabe)
			printf("Kleiner! Neuer versuch: ");
		else
			printf("Mehr!!! Neuer versuch: ");
		scanf("%i", &eingabe);
		printf("\n");
	}
	printf("GEFUNDEN!!! Es war die %i :D", z);
}