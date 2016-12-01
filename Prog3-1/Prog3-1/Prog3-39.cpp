#include <iostream>
using namespace std;

class Rational {
private:
	long zaehler, nenner;
	long ggT(long a, long b);
public:
	Rational();
	Rational(long z, long n);
	Rational(long gz); // für Ganzzahlen
	Rational(const Rational& r); // Kopierkonstruktor
	Rational& Rational::operator=(const Rational& other);

	friend void add(const Rational& a, const Rational& b);
	friend void sub(const Rational& a, const Rational& b);
	friend void mult(const Rational& a, const Rational& b);
	friend void div(const Rational& a, const Rational& b);

	void set(long z, long n);
	void kehrwert();
	void kuerzen();
	void ausgabe();
};

Rational::Rational() : zaehler(1), nenner(1) {
	cout << "Hier Rational()" << endl;
}

Rational::Rational(long z, long n) : zaehler(z), nenner(n) {
	cout << "Hier Rational(long z, long n)" << endl;
}

Rational::Rational(long gz) : zaehler(gz), nenner(1) {
	cout << "Hier Rational(long gz)" << endl;
}

Rational::Rational(const Rational& r) {
	cout << "Hier Rational(const Rational& r)" << endl;
	zaehler = r.zaehler;
	nenner = r.nenner;
}

Rational& Rational::operator=(const Rational& other) {
	zaehler = other.zaehler;
	nenner = other.nenner;
}

long Rational::ggT(long a, long b) {
	long r;
	do {
		if (a < b) {
			r = a;
			a = b;
			b = r;
		}
		r = a % b;
		if (r != 0) {
			a = b;
			b = r;
		}
	} while (r != 0);
	return b;
}

void Rational::add(const Rational& a, const Rational& b) {
	long sn = a.nenner;

	long aNenner = a.nenner * b.nenner;
	long aZaehler = a.zaehler * b.nenner;

	long bNenner = b.nenner * sn;
	long bZaehler = b.zaehler * sn;

	nenner = aNenner;
	zaehler = aZaehler + bZaehler;
}

void Rational::mult(const Rational& a, const Rational& b) {
	long sn = a.nenner;

	long aNenner = a.nenner * b.nenner;
	long aZaehler = a.zaehler * b.nenner;

	long bNenner = b.nenner * sn;
	long bZaehler = b.zaehler * sn;

	nenner = aNenner;
	zaehler = aZaehler + bZaehler;
}

void Rational::sub(const Rational& a, const Rational& b) {
	long sn = a.nenner;

	long aNenner = a.nenner * b.nenner;
	long aZaehler = a.zaehler * b.nenner;

	long bNenner = b.nenner * sn;
	long bZaehler = b.zaehler * sn;

	nenner = aNenner;
	zaehler = aZaehler - bZaehler;
}

void Rational::div(const Rational& a, const Rational& b) {
	long sn = a.nenner;

	long aNenner = a.nenner * b.nenner;
	long aZaehler = a.zaehler * b.nenner;

	long bNenner = b.nenner * sn;
	long bZaehler = b.zaehler * sn;

	nenner = aNenner;
	zaehler = aZaehler + bZaehler;
}

void Rational::set(long z, long n) {
	zaehler = z;
	nenner = n;
}

void Rational::kehrwert() {
	long temp = zaehler;
	zaehler = nenner;
	nenner = temp;
}

void Rational::ausgabe() {
	cout << zaehler << " / " << nenner << endl;
}

void Rational::kuerzen() {
	int ggt = ggT(zaehler, nenner);
	zaehler /= ggt;
	nenner /= ggt;
}

int main() {
	Rational a(1, 8);
	a.ausgabe();
	Rational b(1, 4);
	Rational c;
	c.ausgabe();
	c.add(a, b);
	c.ausgabe();
	c.kuerzen();
	c.ausgabe();
	cin.peek();
}