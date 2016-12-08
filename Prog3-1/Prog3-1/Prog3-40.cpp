#include <iostream>
#include <string>
using namespace std;

class Kunde
{
	static int Kunden;
	int m_nummer;
	string m_name;

public:
	Kunde(int nummer = 0, const string& name = "");
	~Kunde();
	int getNummer() const;
	const string& getName() const;
	int getKunden() {
		return Kunden;
	}

	void ausgeben(){
		cout << m_nummer << ": " << m_name << " || Kunden Anzahl: " << Kunde::Kunden << endl;
	}

};

int Kunde::getNummer() const {
	return m_nummer;
}

const string& Kunde::getName() const {
	return m_name;
}

Kunde::Kunde(int nummer, const string& name) : m_nummer(nummer), m_name(name) {
	Kunden++;
}

Kunde::~Kunde() {
	Kunden--;
}

int Kunde::Kunden = 0;

int main() {
	Kunde a(0, "Peter");
	Kunde b(2, "Manfred");
	Kunde c(5, "Dieter");
	Kunde d(8, "Niclas");

	c.ausgeben();
	a = b;

	a.ausgeben();

	cin.peek();
	return 0;
}

