#include <iostream>
#include <ctime>
using namespace std;

#define BCONST 9757
#define CCONST 6925
#define MCONST 32768

class Random {
public:
	void randomSeed();
	void init(int min, int max);
	int rand();
	Random();
	Random(unsigned int m);
	Random(int m, int n);
	~Random();
private:
	int seed = 0;
	bool first = true;
	int g_iMin = 0;
	int g_iMax = 0;
};

int seed = 0;
bool first = true;

int g_iMin = 0;
int g_iMax = 0;

Random::Random() : g_iMin(0), g_iMax(MCONST) {
	init(g_iMin, g_iMax);
}

Random::Random(unsigned int m) : g_iMin(-m), g_iMax(m) {
	init(g_iMin, g_iMax);
}

Random::Random(int m, int n) : g_iMin(m), g_iMax(n) {
	init(g_iMin, g_iMax);
}

Random::~Random(){}

void Random::randomSeed() {
	if (first) {
		seed = (int)(time(0) % MCONST);
		first = !first;
	}
}

void Random::init(int min, int max) {
	randomSeed();

	g_iMin = min;
	g_iMax = max;
}


int Random::rand() {
	seed = (int)((seed * BCONST + CCONST) % MCONST);
	return (g_iMin + (int)((double)(g_iMax - g_iMin) * seed / MCONST));
}

int main() {
	// Test Case Kopiert von Prof. Wieland
	Random r1, r2(10), r3(-20, 50);

	cout << "1. Folge von 10 Zufallszahlen:\n";
	for (int i = 0; i < 10; i++)
		cout << r1.rand() << " ";

	cout << endl << endl;

	cout << "2. Folge von 10 Zufallszahlen:\n";
	for (int i = 0; i < 10; i++)
		cout << r2.rand() << " ";

	cout << endl << endl;

	cout << "3. Folge von 10 Zufallszahlen:\n";
	for (int i = 0; i < 10; i++)
		cout << r3.rand() << " ";

	cout << endl;

	cin.get();
	return 0;
}