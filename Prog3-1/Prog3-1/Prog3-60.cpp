#include <iostream>
#include <algorithm>
using namespace std;


static int n = 0;
bool printif(int i) {
	cout << "v: " << i << endl;
	if (i < 0) { n++; return false; }
	return true;
}

int f(void)
{

	int a[10] = { 3, 5, -8, 13, 21, 34, -55, 89, 144, 233 };
	int n = 0;

	/*if (all_of(a, a + 10, [&](int v) -> bool {
		cout << "v: " << v << endl;
		if (v < 0) { n++; return false; }
		return true;
	}))
		cout << n << ", +" << endl;
	else
		cout << n << ", -" << endl;*/

	if(for_each(a, a + 10, printif))
		cout << n << ", +" << endl;
	else
		cout << n << ", -" << endl;
	return 0;

}

int main() {
	f();
	system("PAUSE");
	return 0;
}

/*

v: 3
v: 5
v: -8
1, -
Drücken Sie eine beliebige Taste . . .

*/