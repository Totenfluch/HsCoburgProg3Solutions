#include <iostream>
#include <set>
#include <time.h>
using namespace std;

int main() {
	set<int> s1 = set<int>();
	set<int>::iterator it;
	srand(time(NULL));

	for (int i = 1; i < 47; i++)
		s1.insert(i);

	for (int i = 1; i < 8; i++) {
		it = s1.begin();
		int rn = (int)(rand() % (46-i));
		for (int x = 0; x < rn; x++)
			++it;
		int my_rand_val = *it;
		it = s1.erase(it);
		if (i != 7)
			cout << "Zahl: " << i << ": " << my_rand_val << endl;
		else
			cout << "Superzahl: " << my_rand_val << endl;
	}

	system("PAUSE");
	return 0;
}