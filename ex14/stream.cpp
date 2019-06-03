#include <iostream>
#include <fstream> // ifstream ofstream
#include <sstream>
using namespace std;

// stringstream istream, ostream
void printAlaBala(ostream & out) {
	out << "ala bala nitsa  .... " << endl;
}

int main() {
	// int x;
	// cin >> x;

	// cin <------ istream
	// ifstream

	// cout <-------- ostream


	cout << "ala bala" << endl;
	printAlaBala(cout);

	// ofstream
	ofstream out("myfile.txt");
		// truncate = delete the content and start over
		// append = add content to the end of the file | ios_base::app
	out << "ala bala in file" << endl;
	printAlaBala(out);
	out.close(); // !!!!!!!!

	

	stringstream ss;
	ss << "ala bala" << " " << endl << "aaaaand: [" << 5 << "]" << endl;
	cout << ss.str();
	printAlaBala(ss);
	cout << "----------------------------------- " << endl;
	cout << ss.str();
	cout << "----------------------------------- " << endl;

	int myint;
	stringstream sin("150 within rectangle 0 0 30 30");
	sin >> myint;
	cout << myint << endl;



	return 0;
}