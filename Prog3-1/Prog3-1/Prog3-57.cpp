#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, string> myMap = map<string, string>();
	cout << "Kürzel Eingeben um Flughafen zu erhalten:" << endl;
	myMap.insert(make_pair("JFK", "New York(J.F.Kennedy)"));
	myMap.insert(make_pair("MUC", "München"));
	myMap.insert(make_pair("FRA", "Frankfurt Rhein / Main"));
	myMap.insert(make_pair("TXL", "Berlin Tegel"));
	myMap.insert(make_pair("DUS", "Düsseldorf"));

	string a1;
	cin >> a1;
	string x = myMap.at(a1);
	cout << x << endl;
	system("PAUSE");
	return 0;
}