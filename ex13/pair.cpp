#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
class Pair {
public:
	Pair(T1 left, T2 right) {
		this->left = left;
		this->right = right;
	}

	void print() {
		cout << "Pair ============================" << endl;
		cout << "Left: " << left << endl;
		cout << "Right: " << right << endl;
		cout << "=================================" << endl;
	}

public:
	T1 left;
	T2 right;
};

int main() {
	Pair<int, int> pInt(5, 42);
	pInt.print();
	cout << "sum: " << (pInt.left + pInt.right) << endl;

	Pair<string, int> pString("ala bala", 42);
	pString.print();
	// cout << "sum: " << (pString.left + pString.right) << endl;

	Pair<string, string> pStr("ala ", "bala");
	pStr.print();
	cout << "concat: " << (pStr.left + pStr.right) << endl;
	cout << "left str len: " << pStr.left.length() << endl;

	return 0;
}
