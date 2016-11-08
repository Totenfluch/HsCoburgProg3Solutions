int main(void) {
	// A)

	// a ist ein Zeiger auf einen konstanten float Wert.
	const float *a;

	// b ist ein konstanter Zeiger auf eine float-Variable.
	float x;
	float * const b = &x;

	// c ist ein Zeiger auf einen konstanten Zeiger mit eine float
	float * const *c;

	// d ist ein Vektor mit 3 Zeigern auf float-Variablen.
	float * d[3];

	// e ist ein Zeiger auf einen Vektor mit 3 Zeigern auf float-Variablen.
	float * (*e)[3];

	// B)
	*d + 3;
	d[1];
	// ->

}