#include <iostream>


class aids {
public:
	aids() {
		std::cout << "Initialisierung" << std::endl;
	}
	~aids() {
		std::cout << "Aufraeumen" << std::endl;
	}

}; aids superaids;

int main(){
	std::cout << "Hello World!" << std::endl;
	return 0;
}
