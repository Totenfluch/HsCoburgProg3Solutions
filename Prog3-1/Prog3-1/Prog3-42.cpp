#include <iostream>
using namespace std;

class Basis {
private:
	Basis* daten;
public:
	Basis();
	~Basis();
};

Basis::Basis() {
	daten = new Basis[100];
}

Basis::~Basis() {
	delete[] daten;
}

class superBasis : public Basis {

};

int main() {
	cin.peek();
	return 0;
}