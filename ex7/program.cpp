#include <iostream>
#include "libs/student.h"
#include "libs/student.h"
#include "libs/student.h"
#include "libs/student.h"
#include "libs/student.h"
#include "libs/university.h"

using namespace std;

#define ALABALA(x) for (int i = 0; i < x; i++)

int main() {
	ALABALA(strlen("ala bala")) {
		cout << "From ala bala: " << i << endl;		
	}
	
	#ifndef X
	cout << "xxxxxxxxxxxxx" << endl;
	#endif
	#ifndef X
	#define X
	cout << "xxxxxxxxxxxxx" << endl;
	#endif
	#ifndef X
	cout << "xxxxxxxxxxxxx" << endl;
	#endif

	Student pesho(123);
	pesho.print();

	University su;
	su.add(pesho);
	su.add(pesho);
	su.add(pesho);
	su.add(pesho);
	su.add(pesho);
	su.print();
	return 0;
}