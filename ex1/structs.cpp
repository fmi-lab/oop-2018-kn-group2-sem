#include <iostream>
#include <cstring>

using namespace std;

struct ScoredWord {
  char word[21];
  double score;
};

// ScoredWord words[2] = { ... };
// "happy" -> "1"
// "sad" -> "-1"

struct Date { // int
  int year;
  int month;
  int day;
};

struct Person {
  char name[21];
  int age;
  Date birthDate;

  // Default Constructor
  Person() {
    cout << "My Constructor" << endl;
  }

  // Constructor
  Person(const char * name, int age) {
    // this == current variable
    strcpy(this->name, name); // !!!!
    this->age = age;
  }

  // Constructor
  Person(const char * name, int year, int month, int day) {
    // this == current variable
    strcpy(this->name, name); // !!!!
    this->age = 2019 - year;
  }

  // function
  void print() {
    // this; // Person*
    cout << this->name << " (" << this->age << ")" << endl;
    cout << "/"
      << this->birthDate.year << "-"
      << this->birthDate.month << "-"
      << this->birthDate.day
      << "/" << endl;
  }
};

void print(Person p) {
  cout << p.name << " (" << p.age << ")" << endl;
  cout << "/" << p.birthDate.year << "-"
    << p.birthDate.month << "-"
    << p.birthDate.day << "/" << endl;
}

// & -> reference
// * -> pointer
void read(Person* p) {
  cout << "Name: ";
  cin >> p->name;

  cout << "Age: ";
  cin >> (*p).age;

  cout << "Date of Birth: " << endl;
  cout << "Year: ";
  cin >> (p->birthDate).year;
  //     |\_________/
  //Person*   Date

  cout << "Month: ";
  cin >> (*p).birthDate.month;

  cout << "Day: ";
  cin >> p->birthDate.day;
}

Person read() { // overloading
  Person p;
  cout << "Name: ";
  cin >> p.name; // getline ???

  cout << "Age: ";
  cin >> p.age;

  cout << "Date of Birth: " << endl;
  cout << "Year: ";
  cin >> p.birthDate.year;

  cout << "Month: ";
  cin >> p.birthDate.month;

  cout << "Day: ";
  cin >> p.birthDate.day;
  return p;
}

int main() {
  Person p1("Peshooooo", 320);
  p1.print();

  // print(p1);

  // Person pesho;
  // read(&pesho);
  // Person ivan = read();

  // // cout << "///////////////////////////" << endl;
  // print(pesho);
  // print(ivan);

  return 0;
}

