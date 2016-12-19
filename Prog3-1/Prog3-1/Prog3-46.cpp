#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Figur{
public:
	virtual double flaeche() const = 0;
	virtual double umfang() const = 0;
	virtual ~Figur() {};
};

void figurDaten(Figur* f){
	cout << "Flaeche:" << f->flaeche() << endl;
	cout << "Umfang: " << f->umfang() << endl;
}


class Kreis : public Figur {
private:
	double radius;
public:
	double flaeche() const override {
		return radius * radius * 3.141592654;
	}
	double umfang() const override {
		return 2 * 3.141592654 * radius;
	}
	Kreis(int rad) : radius(rad) {};
};

class Viereck : public Figur {
private:
	double laenge;
	double breite;
	double flaeche() const override {
		return laenge * breite;
	}
	double umfang() const override {
		return 2 * laenge + 2 * breite;
	}
public:
	Viereck(double l, double b) : laenge(l), breite(b) {};
};

class Dreieck : public Figur {
private:
	double a;
	double b;
	double c;
	double flaeche() const override {
		return 0.5*a*b;
	}
	double umfang() const override {
		return a + b + c;
	}
public:
	Dreieck(double lol, double polo, double kevin) : a(lol), b(polo), c(kevin) {};
};


int main() {
	Kreis* a;
	Kreis n(25);
	Viereck* b;
	Viereck lol(20.0, 20.0);
	Dreieck* asdf;
	Dreieck psf(10.0, 10.0, 10.0);

	a = &n;
	b = &lol;
	asdf = &psf;
	figurDaten(a);
	figurDaten(b);
	figurDaten(asdf);
	cin.peek();
	return 0;
}