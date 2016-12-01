#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

class Employee {
private:
	int salary = 20000;
	char* name;
public:
	Employee(int newSalaray);
	Employee(Employee& other);
	~Employee();
	int getSalary();
	char* getName();
};

Employee::Employee(int newSalary) {
	salary = newSalary;
	name = new char[80];
}

Employee::Employee(Employee& other) {
	salary = other.salary;
	name = new char[80];
	for (unsigned i = 0; i < 80; i++)
		name[i] = other.name[i];
}

Employee::~Employee() {
	delete[] name;
}

int Employee::getSalary() { 
	return salary; 
}

char* Employee::getName() { 
	return name; 
}

#endif __EMPLOYEE_H__