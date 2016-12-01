#include <iostream>
#include <ctime>
using namespace std;

int seed = 0;
bool first = true;

int g_iMin = 0;
int g_iMax = 0;

int main() {
	
}

int randomSeed() {
	if (first) {
		seed = (int)(time(0) % 32768);
		first = !first;
	}
}

int init(int min, int max) {
	randomSeed();

	g_iMin = min;
	g_iMax = max;

}


long rand() {
	srand(time(0));

}