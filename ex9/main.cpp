#include <iostream>
using namespace std;

struct Person {
	char name[100];
	long dateOfBirth;
};

struct Student {
	char name[100];
	long dateOfBirth;
	int fn;
	char specialty[100];	
};

const char * Person__getName(Person * dis) {
	return dis->name;
}

void Person__print(Person * dis) {
	// ....
}

void Student__print(Student * dis) {
	// ....
}

int main() {
	Person pesho = {"Pesho", 19900411};
	Student ivan = {"Ivan", 19900512, 1234, "KN"};
	cout << "pesho: " << pesho.name << endl;
	cout << "ivan: " << ivan.name
		 << " / " << ivan.specialty << endl;


	Person * pp = &pesho;
	Student * sp = &ivan;
	
	cout << "pesho:" << pp->name << endl;
	pp = (Person*) &ivan;
	cout << "ivan(person) : " << pp->name << endl;
	cout << "ivan(student) : " << sp->name << endl;

	cout << "Person.getName: " << Person__getName(&pesho) << endl;
	cout << "Student.getName: " << Person__getName((Person *) &ivan) << endl;

	// long l = 42;
	// double d = 13;
	// cout << "l: " << l << endl;
	// cout << "d: " << d << endl;
	
	// int * pl = (int*)&l;
	// cout << "p->l: " << (*pl) << endl;
	// pl = (int*)&d;
	// cout << "p->d: " << (*pl) << endl;
	

	return 0;
}