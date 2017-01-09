#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	string s1;
	list<string> woerter(10);
	while (s1 != ".") {
		cout << "Enter some words" << endl;
		cin >> s1;
		woerter.push_front(s1);
		copy(woerter.begin(), woerter.end(),
			ostream_iterator<string>(cout, "\n"));
	}
	system("pause");
	return 0;
}