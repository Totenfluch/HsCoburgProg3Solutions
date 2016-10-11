#include <stdio.h>


int main(void) {
	printf("(1) Celsius to Fahrenheit\n(2) Fahrenheit to Celsius\n->");
	int whatToDo = -1;
	scanf("%d", &whatToDo);
	float temperature = -1.0f;
	printf("Enter the Temperature to convert: ");
	scanf("%f", &temperature);
	if (whatToDo == 1) {
		float result = (5 * (temperature - 32)) / 9;
		printf("Result: %f F", result);
	}else if(whatToDo == 2) {
		float result = ((9 * temperature / 5)) + 32;
		printf("Result: %f °C", result);
	}
	system("PAUSE");
	return 0;
}