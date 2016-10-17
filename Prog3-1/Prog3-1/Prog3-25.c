#include <stdio.h>

struct Point {
	double x;
	double y;
} P1, P2, Gerade;



int main(void) {
	P1.x = -1.1;
	P1.y = 3.5;

	P2.x = 2.4;
	P2.y = -0.7;

	Gerade.x = P2.x - P1.x;
	Gerade.y = P2.y - P1.y;

	double m = Gerade.y / Gerade.x;
	double c = P1.y - m * P1.x;

	printf("Erster Punkt: P1 = (%.1lf, %.1lf)\n", P1.x, P1.y);
	printf("Zweiter Punkt : P2 = (%.1lf, %.1lf)\n", P2.x, P2.y);
	printf("Für die Gerade y = mx + c durch P1 und P2 gilt : m = %.3lf und c = %.3lf\n", m, c);

	system("pause");
	return 0;
}