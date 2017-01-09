#include <string>
#include <iostream>

using namespace std;

class BasisKlasse {

public:

	string name1() { return "BasisKlasse::name1"; }
	virtual string name2() { return "BasisKlasse::name2"; }
	virtual ~BasisKlasse() { cout << "BasisKlasse::~BasisKlasse"; };

};


class AbgelKlasse : public BasisKlasse {

public:

	string name1() { return " AbgelKlasse::name1"; }
	virtual string name2() { return " AbgelKlasse::name2"; }
	virtual ~AbgelKlasse() { cout << " AbgelKlasse::~AbgelKlasse"; };

};



int main() {

	AbgelKlasse *akl = new AbgelKlasse();
	BasisKlasse* bkl = akl;
	cout << akl->name1() << endl;
	cout << akl->name2() << endl;
	cout << bkl->name1() << endl;
	cout << bkl->name2() << endl;
	delete bkl;
	system("pause");
	return 0;

}

/*
Output try:
	 AbgelKlasse::name1
	 AbgelKlasse::name2
	BasisKlasse::name1
	 AbgelKlasse::name2 // virtual in bk
	 AbgelKlasse::~AbgelKlasse
	BasisKlasse::~BasisKlasse
*/