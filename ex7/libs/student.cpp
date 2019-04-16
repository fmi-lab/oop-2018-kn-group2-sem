#include <iostream>
#include "student.h"

using namespace std;

Student::Student(int fn) {
	this->fn = fn;
}

Student::~Student() {
}

Student::Student(const Student& other) {
	this->fn = other.fn;
}

Student& Student::operator=(const Student& other) {
	this->fn = other.fn;
	return *this;	
}

void Student::print() {
	cout << "FN: " << fn << endl;
}
