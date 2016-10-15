#include <stdio.h>

int istSchaltJahr(int jahr);
int getTageInMonat(int monat, int jahr);

int main(void) {
	int jahr = 0;
	int monat = 0;
	int tag = 0;
	printf("Bitte Datum eingeben: \n");
	scanf("%i.%i.%i", &tag, &monat, &jahr);

	int tagImJahr = 0;
	tagImJahr += tag;
	for (int i = 1; i < monat; i++)
		tagImJahr += getTageInMonat(i, jahr);

	printf("\nTage vergangen: %i", tagImJahr);
	system("pause");
	return 0;
}

int istSchaltJahr(int jahr) {
	if ((jahr % 4 == 0) && (jahr % 100 != 0) || (jahr % 400 == 0))
		return 1;
	return 0;
}

int getTageInMonat(int monat, int jahr) {
	if (monat == 2)
		if (istSchaltJahr(jahr))
			return 29;
		else
			return 28;
	else
		if (monat % 2 == 0)
			return 31;
		else
			return 30;
}