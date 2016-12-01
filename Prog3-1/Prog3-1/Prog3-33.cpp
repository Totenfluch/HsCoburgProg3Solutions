// Konstruktor
// Destruktor
// Kopier Konstruktor ( Vektor v = v2; )
// -- variablen initialisiere
// -- speicher anlegen
// -- speicher zuweisen 
// Zuweisungs Operator ( v = v3; )
// -- speicher freigeben
// -- speicher anlegen
// -- speicher zuweisen
// -- kopieren der inhalte
// -- rückgabe
// Getter -- mit assert + inline
// Setter -- mit assert + inline
// resize

class spareVector {
public:
	spareVector();
	spareVector(int laenge);
	spareVector(spareVector&  vek);
	~spareVector();
	double getEntry(int i);
	void setEntry(int i, double val);
	spareVector& spareVector::operator=(const spareVector& other);
private:
	int size;
	double* v;

};

spareVector::~spareVector() {
	delete[] v;
}

spareVector::spareVector() : size(50), v(nullptr) {
	v = new double[size];
}

spareVector::spareVector(int laenge) : size(laenge), v(nullptr) {
	v = new double[size];
}

spareVector::spareVector(spareVector& vec) : size(vec.size), v(nullptr) {
	v = new double[size];
	for (int i = 0; i < size; i++)
		v[i] = vec.v[i];
}

spareVector& spareVector::operator=(const spareVector& other) {
	if (this != &other) {
		if (v)
			delete[] v;
		size = other.size;
		v = new double[size];
		for (unsigned i = 0; i < size; i++)
			v[i] = other.v[i];
	}
	return (*this);
}

double spareVector::getEntry(int i) {
	if (v != nullptr)
		return v[i];
	else
		return -1;
}

void spareVector::setEntry(int x, double val) {
	if (v == nullptr)
		return;
	if(val != 0)
		v[x] = val;
}