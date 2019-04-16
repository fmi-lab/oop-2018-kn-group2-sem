#include <iostream>
#include "university.h"

using namespace std;

void University::add(Student s) {
	numberOfStudents++;
	cout << "Adding: ";
	s.print();
}

void University::print() const {
	cout << "Students: " << numberOfStudents << endl;
}

