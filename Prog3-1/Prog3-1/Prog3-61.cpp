#include <iostream>
using namespace std;


class Set {
private:

	int  maxCard;    // maximale Elementzahl
	int* elems;     // Elemente der Menge
	int  card;      // aktuelle Kardinalität

public:
	enum ErrCode { OK, ADDERR, RMVERR };

	Set(int size = 50);

	Set(const Set& anotherSet);

	~Set();

	Set& operator=(const Set& anotherSet);
	friend    bool operator&    (int, Set);  // Test auf Mitgliedschaft
	friend    bool operator==   (const Set&, const Set&);  // Gleichheit
	friend    bool operator!=   (const Set&, const Set&);  // Ungleichheit
	friend    Set  operator*    (const Set&, const Set&);  // Schnitt
	friend    Set  operator+    (const Set&, const Set&);  // Vereinigung
	friend    Set  operator-    (const Set&, const Set&);  // Mengenminus
	friend    bool operator<=   (const Set&, const Set&);  // Teilmenge
	friend    ostream& operator<< (ostream&, const Set&); // Ausgabe
	friend    istream& operator >> (istream&, Set&); // Eingabe eines Elements

	ErrCode   AddElem(int);                 // Hinzufügen
	ErrCode   RmvElem(int);                 // Herausnehmen

};

Set::Set(int size = 50) : maxCard(size) {
	elems = new int[size];
}

Set::Set(const Set& anotherSet) {
	maxCard = anotherSet.maxCard;
	card = anotherSet.card;
	elems = new int[anotherSet.maxCard];
	for (int i = 0; i < anotherSet.maxCard; i++)
		elems[i] = anotherSet.elems[i];
}

Set::~Set() { 
	delete[] elems; 
}

Set& Set::operator=(const Set& anotherSet){
	maxCard = anotherSet.maxCard;
	card = anotherSet.card;
	delete[] elems;
	elems = anotherSet.elems;
}

bool operator&(int i, Set s) {
	for (int i = 0; i < s.maxCard; i++)
		if (s.elems[i] == i)
			return true;

	return false;
}

bool operator==   (const Set& s1, const Set& s2) {
	if (s1.maxCard != s2.maxCard)
		return false;
	if (s1.card != s2.card)
		return false;
	for (int i = 0; i < s1.maxCard; i++)
		if (s1.elems[i] != s1.elems[i])
			return false;
	return true;
}

bool operator!=   (const Set& s1, const Set& s2) {
	if (s1.maxCard != s2.maxCard)
		return true;
	if (s1.card != s2.card)
		return true;
	for (int i = 0; i < s1.maxCard; i++)
		if (s1.elems[i] != s1.elems[i])
			return true;
	return false;
}


Set  operator*    (const Set& s1, const Set& s2) {
	int* partElems = new int[s1.maxCard];
	int schnittElems = 0;
	for (int i = 0; i < s1.maxCard; i++) {
		for (int x = 0; x < s2.maxCard; i++) {
			if (s1.elems[i] == s2.elems[i]) {
				schnittElems++;
				partElems[schnittElems++] = s1.elems[i];
				if (x >= s1.maxCard)
					break;
			}
		}
	}
	
	Set s3 = Set(schnittElems);
	s3.maxCard = schnittElems;
	s3.card = schnittElems;
	s3.elems = new int[schnittElems];

	for (int i = 0; i < schnittElems; i++)
		s3.elems[i] = partElems[i];

	return s3;
}