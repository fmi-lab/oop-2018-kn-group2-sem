#include <iostream>
#include <fstream> // ifstream ofstream
#include <sstream>
using namespace std;


/* test file
rect 10 12 50 150

single_choice
Question text ala bala ... 
3
yes
no
maybe
2

multiple_choice
Question text ala bala ... 
3
yes
no
maybe
0,2

short_answer
Question text ala bala ... 
expected answer
*/

class Test {
public:
	void open(string filename) {
		ifstream in(filename);
		read(in);
		in.close();
	}

	// Static Factory Method

	// Factory Method
	Question* createQuestion(string type, istream& in) {
		if (type == "single_choice") {
			return SingleChoiceQuestion::createFrom(in);
			// return new SingleChoiceQuestion();
		} else if (type == "multiple_choice") {
			return new MultipleChoiceQuestion();
		} else if (type == "short_answer") {
			return new ShortAnswerQuestion();
		} else {
			cout << "Error: unknown question type" << endl;
			return NULL;
		}
	}

	void read(istream & in) {
		string firstLine;
		in >> firstLine;

		Question * question = createQuestion(firstLine);
		if (question != NULL) {
			if (question->read(in)) {
				questions.push_back(question);
			}
		}
	}
private:
	vector<Question*> questions;
}


int main() {
	ifstream in("mytest.in");
	


	return 0;
}