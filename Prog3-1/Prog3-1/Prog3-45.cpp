#include <iostream>
using namespace std;

struct LE
{
	float value; /* Daten im Element */
	struct LE* next; /* Zeiger auf nächstes */
	LE() : value(0.0f), next(0) {}
};

class List {
private:
	LE* first; /* erstes Listenelement */
	LE* last; /* letztes Listenelement */
	LE* leArray; /* Array mit Listenelementen */
	unsigned leArraySize; /* Größe des Arrays */
	LE* firstEmpty;
	LE* newLE();
public:

	List(unsigned size = 0);
	List(const List& source);
	List(List&& source);
	~List();
	int append(float value);
	void deleteLE(LE* old);
	List& operator=(const List& source);
	List& operator=(List&& source);
};

List::List(unsigned size) : leArraySize(size) {

}

List::List(const List& source) {

}

List::List(List&& source) {

}

List::~List() {

}

List::newLe() {

}

int List::append(float value) {

}

void List::deleteLE(LE* old) {

}

List& List::operator=(const List& source) {

	return *this;
}


List& List::operator=(List&& source) {

}