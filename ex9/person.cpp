#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "A Person is created" << endl;

		strcpy(this->name, "John Doe");
		this->dateOfBirth = 0;		
	}
	Person(const char * name, long dateOfBirth) {
		cout << "A Person is created with name " << name
		<< " and DOB: " << dateOfBirth << endl;

		strcpy(this->name, name);
		this->dateOfBirth = dateOfBirth;
	}
	~Person() {
		cout << "Destroy this person ... " << endl;
	}

	const char * getName() const {
		return name;
	}

	virtual void print() const {
		cout << "Person" << endl;
		cout << "Name: " << name << endl;
		cout << "DOB: " << dateOfBirth << endl;
		cout << "---------------------" << endl;
	}

protected:
	void setName(const char * name) {
		strcpy(this->name, name);
	}
private:
	char name[100];
	long dateOfBirth;	
};

class Student : public Person {
public:
	Student(const char * name, int age):Person(name, convertToDOB(age)) {
		cout << "A Student is coming" << endl;
	}

	~Student() {
		cout << "Destroy this student ... " << endl;
	}

	int getFN() const {
		return fn;
	}

	virtual void print() const {
		cout << "Student" << endl;
		Person::print( );
		cout << "specialty: " << specialty << endl;
		cout << "FN: " << fn << endl;
		cout << "---------------------" << endl;
	}

private:
	long convertToDOB(int age) {
		return 1000 + age;
	}

private:
	int fn;
	char specialty[100];
};
// Student pesho;
class Teacher : public Person {
public:
	double salary;
	char subjects[100];	
};

int main() {
	Person pesho;
	cout << "Person Name: " << pesho.getName() << endl;
	Student ivan("Ivannnnnn", 19);

	cout << "Student Name: " << ivan.getName() << "/" << ivan.getFN() << endl;
	cout << endl << endl << endl << endl << endl;
	pesho.print();
	ivan.print();

	Person * pp = &pesho;
	cout << "Pointer to Person|print" << endl;
	pp->print();

	pp = &ivan;
	cout << "Pointer to Student|print" << endl;
	pp->print();

	return 0;
}
