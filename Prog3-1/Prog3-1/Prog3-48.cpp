#include <iostream>
using namespace std;


class Sortierstrategie
{
public:
	Sortierstrategie() {}
	virtual ~Sortierstrategie() {}
	virtual void sortiere(int* arr, int size) = 0;
};

const int MAXGROESSE = 100;

class SortiertesFeld
{
private:
	int*                 arrayn;
	int                  groesse;
	Sortierstrategie*    strategie;

public:
	SortiertesFeld() : groesse(0), strategie(0) {
		arrayn = new int[MAXGROESSE];
	}

	SortiertesFeld(Sortierstrategie* stra) :
		groesse(0), strategie(stra)
	{
		arrayn = new int[MAXGROESSE];
	}

	~SortiertesFeld() {
		delete[] arrayn;
		delete strategie;
	}

	void setzeStrategie(Sortierstrategie* stra);
	void fuegeHinzu(int nummer);
	void gibAus() const;
	void sortiere();
};


void SortiertesFeld::setzeStrategie(Sortierstrategie* stra) {
	strategie = stra;
}

void SortiertesFeld::fuegeHinzu(int nummer) {
	if (groesse >= MAXGROESSE)
		return;
	arrayn[groesse++] = nummer;
}

void SortiertesFeld::gibAus() const{
	for (int i = 0; i < groesse; i++)
		cout << arrayn[i] << endl;
}

void SortiertesFeld::sortiere() {
	strategie->sortiere(arrayn, groesse);
}

class BubbleSort : public Sortierstrategie
{
public:
	BubbleSort() {}
	~BubbleSort() override {}
	void sortiere(int* arr, int size) override;
};

void BubbleSort::sortiere(int* arr, int size) {
	cout << "Sortiert mit bubblesort!" << endl;
}

int main() {
	SortiertesFeld sf = SortiertesFeld();
	sf.fuegeHinzu(4);
	sf.fuegeHinzu(56);
	sf.fuegeHinzu(1);
	sf.fuegeHinzu(-5);
	sf.fuegeHinzu(19);
	BubbleSort bs = BubbleSort();
	sf.setzeStrategie(&bs);
	sf.sortiere();
	sf.gibAus();

	system("PAUSE");
	return 0;
}

