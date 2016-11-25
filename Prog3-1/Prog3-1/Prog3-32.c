#include <stdio.h>

struct kettenglied {

	int wert;
	struct kettenglied* vorg;
	struct kettenglied* nachf;

};

struct kettenglied* position = NULL;

void fuege_ein(int interval);

int main(void) {
	struct kettenglied* p;
	int n;
	fuege_ein(1);
	fuege_ein(2);
	fuege_ein(3);
	position = position->vorg;
	fuege_ein(4);
	position = position->nachf;
	position = position->nachf;

	for (p = position, n = 0; n <= 4; p = p->nachf, n++)
		printf("%i -> ", p->wert);

	getchar();
	return 0;
}

void fuege_ein(int interval) {
	if (!position) {
		position = (struct kettenglied*)malloc(sizeof(struct kettenglied));
		position->wert = interval;
		position->vorg = position;
		position->nachf = position;
	}
	else{
		struct kettenglied* position2 = (struct kettenglied*)malloc(sizeof(struct kettenglied));
		position2->wert = interval;
		position2->vorg = position;
		position2->nachf = position->nachf;
		position->nachf = position2;
	}
}

