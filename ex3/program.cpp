#include <iostream>
using namespace std;

#include "university.cpp"

//
//  Dependency Management
//
//  Program
//        -> Univeristy
//                  -> Student
//        -> Schedule
//  Schedule
//        -> Univeristy
//                  -> Student
//
//  Program
//        -> Univeristy
//        -> Student
//

/*
  Each class is in separate file named as the class.
  E.g. class University -> university.h
                        -> university.cpp

  // Java
  // C#
*/

// State (Състояние) = Всички полета на класа


int main() {
  // University u;
  University uni("SU");
  cout << "OK: " << uni.getName() << endl;


  return 0;
}
