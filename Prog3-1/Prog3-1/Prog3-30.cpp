#include <iostream>
#include <algorithm>
using namespace std;

int n = 0;
bool vorz(int v) {
	if (v < 0) { 
		n++; return false; 
	}
	return true;
}

int f1()
{

	int a[10] = { 3, 5, -8, 13, 21, 34, -55, 89, 144, 233 };
	if (all_of(a, a + 10, [](int a)->bool {n++; return a < 0; }))
		cout << n << ", +" << endl;
	else
		cout << n << ", -" << endl;

	return 0;
}

int main() {
	f1();
	cin.peek();
	return 0;
}