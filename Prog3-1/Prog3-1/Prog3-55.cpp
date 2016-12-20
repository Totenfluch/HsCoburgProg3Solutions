#include <iostream>
using namespace std;

template<int n>
struct Fakultaet {
	static const int wert = Fakultaet<n - 1>::wert * n;
};

template<> struct Fakultaet<0> {
	static const int wert = 1;
};

int main() {
	const int x = Fakultaet<6>::wert;
	cout << x << endl;
	cin.peek();
	return 0;
}