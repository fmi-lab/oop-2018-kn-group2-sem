#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name) {
		this->name = name;
	}

	virtual void print() const {
		cout << "Person: " << name << endl;
	}
private:
	string name;
};

class Student: public Person {
public:
	Student(string name, string fn):Person(name) {
		this->fn = fn;
	}

	void print() const {
		cout << "Student: " << fn << endl;
	}
private:
	string fn;
};

class Teacher: public Person {
public:
	Teacher(string name, string department):Person(name) {
		this->department = department;
	}

	void print() const {
		cout << "Teacher: " << department << endl;
	}
private:
	string department;
};

class Teapot {
public:
	void print() {
		cout << "I'm a teapot" << endl;
	}
};

template <typename T>
void print(T p) {
	p.print();
}

void printHuman(Person& p) {
	p.print();
}


int main() {
	Person person("Pesho");
	Student student("Gosho", "12345");
	Teacher teacher("Gandalf", "DSE");

	print(person);
	print(student);
	print(teacher);

	print<Person>(person);
	print<Student>(student);
	print<Teacher>(teacher);
	print<Person>(teacher);

	Teapot teapot;
	print(teapot);

	printHuman(person);
	printHuman(student);
	printHuman(teacher);
	// printHuman(teapot);  -- XXX

	return 0;
}








