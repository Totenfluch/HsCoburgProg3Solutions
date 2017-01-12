#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Person {
private:

	string name;
public:
	Person(const string& nm) : name(nm) {};
	const string& getName() const { return name; };
};

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	os << obj.getName();
	return os;
}

bool operator== (const Person &c1, const Person &c2)
{
	return c1.getName().compare(c2.getName()) == 0;
}

class Kontakte {
private:
	list<Person> kontakt;
public:
	Kontakte() {};
	void printAll();
	Person contains(string n);
	void addContact(Person p);
};

void Kontakte::printAll() {
	for (list<Person>::iterator i = kontakt.begin(); i != kontakt.end(); ++i)
		cout << *i << endl;
}


void Kontakte::addContact(Person p) {
	kontakt.push_front(p);
}

Person Kontakte::contains(string n) {
	auto result = find(kontakt.begin(), kontakt.end(), Person(n));
	if (result != kontakt.end())
		return *result;
	else
		return "Not found";
}

int main() {
	Person p1 = Person("Peter");
	Person p2 = Person("Dieter");
	Person p3 = Person("Brake");
	Person p4 = Person("Bingo");
	Person p5 = Person("Stefan");

	Kontakte conts = Kontakte();
	conts.addContact(p1);
	conts.addContact(p2);
	conts.addContact(p3);
	conts.addContact(p4);
	conts.addContact(p5);

	cout << conts.contains("Peter") << " " << conts.contains("Lol") << endl;
	conts.printAll();
	system("PAUSE");
	return 0;
}