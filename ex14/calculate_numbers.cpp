#include <iostream>
#include <fstream> // ifstream ofstream
#include <sstream>
using namespace std;

void calculateSum(istream & in, ostream & out) {
	int n;
	in >> n;

	double sum = 0;
	for (int i = 0; i < n; i++) {
		double x;
		in >> x;
		sum += x;
	}

	out << sum << endl;
}

int main() {
	// ifstream in("input.txt");
	// ofstream out("actual_out.txt");

	stringstream input_test1("6\n1.1 1.2 1.3 1.4 1.5 1.6");
	stringstream input_test2("5\n1.1 1.2 1.3 1.4 1.5");
	stringstream input_test3("10\n1 1 1 1 1 1 1 1 1 1");

	stringstream output_test1("8.1\n");
	stringstream output_test2("6.5\n");
	stringstream output_test3("10\n");

	stringstream actual_out1;
	stringstream actual_out2;
	stringstream actual_out3;

	calculateSum(input_test1, actual_out1);
	calculateSum(input_test2, actual_out2);
	calculateSum(input_test3, actual_out3);

	if (output_test1.str() == actual_out1.str()) {
		cout << "Test 1 - OK" << endl;
	} else {
		cout << "Test 1 - NOK" << endl;
	}

	if (output_test2.str() == actual_out2.str()) {
		cout << "Test 2 - OK" << endl;
	} else {
		cout << "Test 2 - NOK" << endl;
	}

	if (output_test3.str() == actual_out3.str()) {
		cout << "Test 3 - OK" << endl;
	} else {
		cout << "Test 3 - NOK" << endl;
	}


	// in.close(); //!!!	
	// out.close();

	return 0;
}