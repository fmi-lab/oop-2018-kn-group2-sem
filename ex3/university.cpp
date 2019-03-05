#include <iostream>
#include <cstring>
using namespace std;

#include "student.cpp"
const int MAX_NUMBER_OF_STUDENTS = 1000;

class University {
public:
  University(const char * name) {
    // Same level of abstraction
    // strcpy(this->name, name); // Code Smell
    setName(name);
    setNumberOfStudents(0);
    setOpenStudentPositions(0);
  }
  /*
    University(const char * name, int numberOfStudents) {
      0) strcpy --- >>> state
      1) setNumberOfStudents
                0) ---->>> state
      1) setName
                0) ---->>> state
  */

  // - void
  // - Student* - масив от новите свободни места
  // - University& - method chaining
  // Error handling
  // - bool - is successful
  // - int - error code
  // - int - колко отворени места са отворени
  // - char* - цялото изречение с грешката -> bad design & implementation

  void openNewYearStudentPositions(int n) {
    openStudentPositions += n;
    // setOpenStudentPositions(openStudentPositions + n);
    // setOpenStudentPositions(getOpenStudentPositions() + n);
    // incrementOpenStudentPositions(n);
  }

  // error handling?
  // enrollStudent(Student student) {

  // }

  // CommandQuerySeparation
  // Command -> change your state ===> set
  // Query -> read the state ===> get
  // https://martinfowler.com/bliki/CommandQuerySeparation.html
  const char * getName() const {
    return name;
  }
private:
  // set/get methods
  // селектор/мутатор

  // C# - property vs field
  void setName(const char * name) {
    strcpy(this->name, name);
  }

  void setNumberOfStudents(int numberOfStudents) {
    this->numberOfStudents = numberOfStudents;
  }

  void setOpenStudentPositions(int openStudentPositions) {
    this->openStudentPositions = openStudentPositions;
  }

  char name[51];
  Student students[MAX_NUMBER_OF_STUDENTS];
  int numberOfStudents;
  int openStudentPositions;
};
