#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Figur {
public:
	virtual double flaeche() const = 0;
	virtual double umfang() const = 0;
	virtual ~Figur() {};
};

void figurDaten(Figur* f) {
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
	Figur& operator=(const Kreis& k){
		return Kreis(k.radius);
	}
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
	Figur& operator=(const Viereck v) {
		return Viereck(v.laenge, v.breite);
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
	Figur& operator=(const Dreieck d) {
		new Dreieck(d.a, d.b, d.c);
	}
public:
	Dreieck(double aa, double bb, double cc) : a(aa), b(bb), c(cc) {};
};

class GeometrieContainer
{
private:
	int anzahl;
	Figur** figuren;

public:
	GeometrieContainer();
	GeometrieContainer(int size);
	GeometrieContainer(const GeometrieContainer& gc);
	Figur** getFiguren() { return figuren; };
	
};

GeometrieContainer::GeometrieContainer() : anzahl(50) {
	figuren = new Figur*[50];
	for (int i = 0; i < 50; i++)
		figuren[i] = new Dreieck(10.0*i, 10.0*(i + 2), 10.0*(i + 1));
}

GeometrieContainer::GeometrieContainer(int size) : anzahl(size){
	figuren = new Figur*[size];
	for (int i = 0; i < size; i++)
		figuren[i] = new Dreieck(10.0*i, 10.0*(i+2), 10.0*(i+1));
}

GeometrieContainer::GeometrieContainer(const GeometrieContainer& gc) {
	cout << "Hier Kopierkonstruktor" << endl;
	GeometrieContainer gc2 = GeometrieContainer(gc.anzahl);
	for (int i = 0; i < gc.anzahl; i++) {
		Figur* copyFigur = new Figur(gc.figuren[i]);
		copyFigur = gc.figuren[i]
		gc2.figuren[i] = ;
	}
}


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

	GeometrieContainer* ptr = new GeometrieContainer();
	GeometrieContainer glol(*ptr);

	delete ptr;
	figurDaten(glol.getFiguren()[0]);
	cin.peek();
	return 0;
}


// a) Es sind nur zeiger und es muss kein neuer speicher für bereits vorhandene Elemente angelegt werden


