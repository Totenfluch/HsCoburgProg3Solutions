#include <iostream>
#include <set>
#include <time.h>
#include <algorithm>    // std::random_shuffle
using namespace std;

int main() {
	set<int> s1 = set<int>();
	for (int i = 1; i < 47; i++)
		s1.insert(i);
	random_shuffle(s1.begin(), s1.end());

	for (int i = 0; i < 8; i++)
		cout << "Zahl " << i << " :" << (*s1.begin() + i) << endl;
	

	system("PAUSE");
	return 0;
}