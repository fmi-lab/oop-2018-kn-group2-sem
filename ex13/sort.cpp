#include <iostream>
#include <string>
using namespace std;

// strcmp
// -1, 0, 1 <--- comperator(T&, T&)

template <typename T>
void sort(T * arr, int n, int (*cmp)(T&, T&)) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cmp(arr[i],arr[j]) > 0)   {
				swap(arr[i], arr[j]);
			}
		}
	}
}

template <typename T>
void print(T * arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int intcmp(int& a, int& b) {
	return a < b ? -1 : (a == b ? 0 : 1);
}

int revintcmp(int& a, int& b) {
	return intcmp(b, a);
}

int funkycmp(int& a, int& b) {
	if (a % 2 != b % 2) {
		if (a % 2 == 1) {
			return -1;
		} else {
			return 1;
		}
	}
	if (a % 2 == 1) {
		// odd
		return intcmp(a, b);
	} else {
		// even
		return intcmp(b, a);
	}
}

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	void print(ostream& out) {
		out << name << "(" << age << ")" << endl;
	}

	bool operator<(Person& p) {
		return age < p.age;
	}

	int getAge() const {
		return age;
	}

private:
	string name;
	int age;
};

ostream& operator<<(ostream& out, Person & p) {
	p.print(out);
	return out;
}

int personCmp(Person& p1, Person& p2) {
	if (p1 < p2) {
		return -1;
	}
	if (p2 < p1) {
		return 1;
	}
	return 0;
}

int revPersonCmp(Person& p1, Person& p2) {
	return personCmp(p2, p1);
}

int funkycmp(Person& p1, Person& p2) {
	int p1age = p1.getAge();
	int p2age = p2.getAge();
	return funkycmp(p1age, p2age);
}

// 1 3 5 7 9 10 8 6 4 2

int main() {
	int (*cmp)(int&, int&) = intcmp;
	cmp = revintcmp;

	int myintarr[] = {7,9,10,3,1,8,4,5,6,2};
	print(myintarr, 10);
	sort(myintarr, 10, intcmp);
	print(myintarr, 10);
	sort(myintarr, 10, revintcmp);
	print(myintarr, 10);
	sort(myintarr, 10, funkycmp);
	print(myintarr, 10);

	Person people[10] = {
		Person("pesho", 13),
		Person("ivan", 14),
		Person("pesho", 15),
		Person("ivan", 12),
		Person("pesho", 11),
		Person("ivan", 14),
		Person("pesho", 15),
		Person("ivan", 21),
		Person("pesho", 17),
		Person("ivan", 13)
	};
	print(people, 10);
	sort(people, 10, personCmp);
	print(people, 10);
	sort(people, 10, revPersonCmp);
	print(people, 10);
	sort(people, 10, funkycmp);
	print(people, 10);

	return 0;
}
