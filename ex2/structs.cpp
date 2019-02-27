#include <iostream>

using namespace std;

// public constructors
// public methods
// public fields

// private constructors
// private methods
// private fields

// Public API || Interface == all PUBLIC constructors, methods, and fields

// class -> by default: private
// struct -> by default: public

class Person {
public: // модификатор за достъп | access modifier
  Person() {   // Default Constructor
    cout << "# Default Constructor" << endl;
    // < празно тяло
  }

  void read() { // функция, член-функция -> методи
    cout << "Name: ";
    cin >> this->name;
    cout << "Age: ";
    cin >> age;
  }

  void print() {
    cout << name << " (" << age << ")" << endl;
  }

private:
  Person(const char * name, int age) { // За общо ползване
    cout << "# name, age Constructor" << endl;
    strcpy(this->name, name);
    this->age = age;
  }

  char name[21]; // променливи -> полета, член-данна, fields || attributes
  int age;
  // Състояние = State = all fields of the struct / class
}; // съставен тип данни

/*
void Person____read(Person * this) {

}

Person* Person____Person(Person * this, const char * name, int age) {
  strcpy(this->name, name);
  this->age = age;


  return this;
}
*/


int main() {
  Person ivan;
  ivan.read();
  ivan.print();

  // Person mimi("Mimi", 21);
  // mimi.print();

  // cout << mimi.name << endl;
  // cout << mimi.age << endl;

  return 0;
}
