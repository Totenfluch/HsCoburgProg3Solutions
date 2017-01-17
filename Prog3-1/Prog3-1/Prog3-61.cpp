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
	friend    Set  operator-    (const Set&, const Set&);  // Mengenminus a-b
	friend    bool operator<=   (const Set&, const Set&);  // Teilmenge 
	friend    ostream& operator<< (ostream&, const Set&); // Ausgabe
	friend    istream& operator >> (istream&, Set&); // Eingabe eines Elements

	ErrCode   AddElem(int);                 // Hinzufügen
	ErrCode   RmvElem(int);                 // Herausnehmen

};

Set::ErrCode Set::AddElem(int i) {
	if (card != maxCard) {
		elems[i] = i;
		card++;
	}
	else
		return ADDERR;
	return OK;
}

Set::ErrCode Set::RmvElem(int i){
	int found = -1;
	for (int i = 0; i < card; i++) {
		if(elems[i] == i){
			found = i;
			break;
		}
	}
	if (found == -1)
		return RMVERR;
	int* newElems = new int[maxCard];
	for (int i = 0; i < found; i++)
		newElems[i] = elems[i];

	for (int i = found + 1; i < card; i++)
		newElems[i] = elems[i];
	
	delete[] elems;
	elems = newElems;

	return OK;
}

Set::Set(int size) : maxCard(size) {
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
	return *this;
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

	for (int i = 0; i < schnittElems; i++)
		s3.elems[i] = partElems[i];

	return s3;
}

Set  operator+    (const Set& s1, const Set& s2) {
	Set s3 = Set(s1.maxCard + s2.maxCard);
	s3.card = s1.card + s2.card;
	for (int i = 0; i < s1.maxCard; i++)
		s3.elems[i] = s1.elems[i];
	for (int i = 0; i < s2.maxCard; i++)
		s3.elems[i + s1.maxCard - 1] = s2.elems[i];
	return s3;
}

Set  operator-    (const Set& s1, const Set& s2) {
	int* partElems = new int[s1.maxCard];
	int schnittElems = 0;
	for (int i = 0; i < s1.maxCard; i++) {
		for (int x = 0; x < s2.maxCard; i++) {
			bool found = false;
			if (s1.elems[i] == s2.elems[i]) {
				found = true;
				break;
				if (x >= s1.maxCard)
					break;
			}
			if(!found)
				partElems[schnittElems++] = s1.elems[i];
		}
	}

	Set s3 = Set(schnittElems);
	s3.maxCard = schnittElems;
	s3.card = schnittElems;

	for (int i = 0; i < schnittElems; i++)
		s3.elems[i] = partElems[i];

	return s3;
}

bool operator<=   (const Set& s1, const Set& s2) {
	if (s1.maxCard > s2.maxCard)
		return false;
	for (int i = 0; i < s1.maxCard; i++) {
		bool found = false;
		for (int x = 0; x < s2.maxCard; x++) {
			if (s1.elems[i] == s2.elems[x]);
				found = true;
		}
		if (!found)
			return false;
	}
	return true;
}

ostream& operator<< (ostream& os, const Set& s1){
	cout << "Set (" << s1.card << "/" << s1.maxCard << ")" << endl << "Elemenete: ";
	for (int i = 0; i < s1.card; i++)
		if (i != s1.maxCard - 1)
			cout << s1.elems[i] << ", ";
		else
			cout << s1.elems[i];
	cout << endl;
	return os;
}

istream& operator >> (istream& is, Set& s1) {
	cout << "Anzahl der Elemente Eingeben: " << endl;
	int i = 0;
	cin >> i;
	cout << "Bitte " << i << " Elemente eingeben." << endl;
	s1.maxCard = i;
	s1.card = 0;
	for (int i = 0; i < s1.maxCard; i++) {
		cout << "Element " << (i + 1) << " of " << s1.maxCard << endl;
		is >> s1.elems[i];
		s1.card++;
	}
	return is;
}

int main() {
	Set s1 = Set();
	cin >> s1;
	cout << s1;
	system("PAUSE");
	return 0;
}
