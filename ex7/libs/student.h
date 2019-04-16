#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student {
public:
	Student(int fn = 0);
	~Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
	void print();
private:
	int fn;
};

#endif