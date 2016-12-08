#include <iostream>
using namespace std;

class Soundcard
{

private:
	Soundcard();
	Soundcard(const Soundcard& r); // Kopierkonstruktor
	Soundcard& Soundcard::operator=(const Soundcard& other);
	static Soundcard *karte;
public:
	Soundcard* instance();
	void loadSoundFile(const char* filename);
	void play();

};

Soundcard::Soundcard() {}

void Soundcard::loadSoundFile(const char* filename) {}

void Soundcard::play() {}

Soundcard::Soundcard(const Soundcard& r) {
	if (karte == nullptr)
		karte = new Soundcard();
}

Soundcard& Soundcard::operator=(const Soundcard& other) {
	if (karte == nullptr)
		karte = new Soundcard();
	return *karte;
}

Soundcard* Soundcard::instance() {
	if (karte == nullptr) 
		karte = new Soundcard();
	return karte;
}

Soundcard* Soundcard::karte = 0;

int main() {

}