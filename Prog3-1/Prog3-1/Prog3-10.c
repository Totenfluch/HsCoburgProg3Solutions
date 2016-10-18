#include <stdio.h>

#define POTENZ(i) ((i)*(i))
#define DRITTEPOTENZ(i) ((i)*(i)*(i))
#define PI 3.1415927

int main(void) {
	float kugelradius = -1;
	printf("Kugel Radius eingeben: ");
	fflush(stdin);
	scanf_s("%f", &kugelradius);

	float kugeloberfläche = 4.0 * PI * POTENZ(kugelradius);
	float kugelvolumen = 4.0 / 3.0 * PI * DRITTEPOTENZ(kugelradius);

	printf("Kugeloberflaeche: %.2f\nKugelvolumen: %.2f\n", kugeloberfläche, kugelvolumen);
	system("pause");
	return 0;
}