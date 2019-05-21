#include <iostream>
#include <string>
#include <vector>
#include "test.h"

using namespace std;


class QuestionsIterator {
public:
	virtual int getNumberOfQuestions() = 0;
	virtual Question* getQuestion(int number) = 0;
}

class ListOfQuestions : public QuestionsIterator {
public:
	void add();

	virtual int getNumberOfQuestions();
	virtual Question* getQuestion(int number);

private:
	std::vector<Question*> questions;
};


int main() {
	ListOfQuestions questions;

	questions.add(
		(new SingleChoiceQuestion("Choose the invalid predefined macro as per ANSI C."))
		->addAnswer("__FILE__")
		->addAnswer("__DATE__")
		->addAnswer("__TIME__")
		->addAnswer("__C++__", 5)
	);

	questions.add(
		(new MultipleChoiceQuestion("What the 4 principles of OOP?"))
		->addAnswer("Encapsulation", 2.5)
		->addAnswer("Inheritance", 2.5)
		->addAnswer("Abstraction", 2.5)
		->addAnswer("Polymorphism", 2.5)
		->addAnswer("Functional programming")
	);

	questions.add(
		(new ShortAnswerQuestion("How to print \\n on the screen ?"))
		->setAnswer("\\n", 5)
	);

	questions.add(
		(new SingleChoiceQuestion("A single line comment in C language source code can begin with _____"))
		->addAnswer(";")
		->addAnswer("//", 2)
		->addAnswer(":")
		->addAnswer("/*")
	);

	questions.add(
		(new MultipleChoiceQuestion("How to print new line in C++"))
		->addAnswer("endl", 2.5)
		->addAnswer("\\n", 2.5)
		->addAnswer("newline")
		->addAnswer("endline")
	);

	questions.add(
		(new ShortAnswerQuestion("Stderr is a standard error."))
		->setAnswer("Yes", 5)
	);

	Test mytest(questions);
	mytest.take(cout, cin);

	return 0;
}