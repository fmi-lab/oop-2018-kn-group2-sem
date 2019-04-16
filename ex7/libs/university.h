#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED
// Pre-processor
#include "student.h"

#define ALABALA_TEXT "alabala"
#define THE_ANSWER 42

class University {
public:
	void add(Student s);
	void print() const;
private:
	Student students[THE_ANSWER];
	int numberOfStudents;
};

#endif