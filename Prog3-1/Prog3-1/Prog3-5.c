#include <stdio.h>


int main(void) {
	printf("Hauptmenue \n\
== == == == == \n\n\
		(A)endern \n\
		(B)eenden \n\
		(D)rucken \n\
		(E)ingeben \n\
		(L)oeschen \n\n\n\
Was wuenschen Sie zu tun ?\n");
	char c = "";
	scanf("%c", &c);
	printf("\n-> %c\n", c);
	switch (c) {
	case 'A': printf("Aendern"); break;
	case 'B': printf("Beenden"); break;
	case 'D': printf("Drucken"); break;
	case 'E': printf("Eingeben"); break;
	case 'L': printf("Loeschen"); break;
	}
	printf("\n");
	system("PAUSE");
	return 0;
}