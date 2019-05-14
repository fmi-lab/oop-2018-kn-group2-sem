#include <iostream>

using namespace std;

class DynArray {
public:
  DynArray(int n) { // Constructor
    arr = new int[n];
    this->n = n;
  }

  DynArray(const DynArray& other) { // Copy-Constructor
    cout << "Copy-Constructor ..... " << endl;
    copy(other);
  }

  // a1 = a2
  DynArray& operator=(const DynArray& other) {
    if (this != &other) {
      deleteObject();
      copy(other);
    }
    return *this;
  }

  ~DynArray() { // Destructor
    cout << "Destructor" << endl;
    deleteObject();
  }

  int get(int position) {
    return arr[position];
  }

  void set(int position, int value) {
    arr[position] = value;
  }

  int getSize() {
    return n;
  }

private:
  void deleteObject() {
    delete[] arr;
  }

  void copy(const DynArray& other) {
    this->n = other.n;
    this->arr = new int[this->n];
    for (int i = 0; i < this->n; i++) {
      this->arr[i] = other.arr[i];
    }
  }

private:
  int * arr;
  int n;
};

DynArray readArray() {
  int n;
  cout << "n = ";
  cin >> n;

  DynArray arr(n);

  cout << "Input elements:";
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.set(i, temp);
  }

  return arr; // Move Constructor
}

void print(DynArray a) {
  for (int i = 0; i < a.getSize(); i++) {
    cout << a.get(i) << " ";
  }
  cout << endl;
}

int main() {
  DynArray arr = readArray();
  print(arr);
  DynArray a1(arr); // Copy-Constructor
  DynArray a2(5);
  DynArray a3 = a1; // Copy-Constructor
  return 0;
}
