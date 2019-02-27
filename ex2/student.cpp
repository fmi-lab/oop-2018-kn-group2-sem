#include<iostream>

using namespace std;


struct Student {
public:
  void read() {
    cout << "Name: ";
    cin.getline(name, 21);

    cout << "FN: ";
    cin >> fn;

    cout << "Specialty: ";
    cin.ignore();
    cin.getline(specialty, 21);

    cout << "Year: ";
    cin >> year;

    cout << "Group: ";
    cin >> group;
  }

  void print() {
    cout << "Name: " << name << endl;
    cout << "FN: " << fn << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Year: " << year << endl;
    cout << "Group: " << group << endl;
  }

  int yearsToGraduation() {
    return 4 - year;
  }

  void moveToUpperYear() {
    year++;
  }

private:
  char name[21];
  int fn;
  char specialty[21];
  int year;
  int group;
};


int main() {
  Student student;

  return 0;
}
