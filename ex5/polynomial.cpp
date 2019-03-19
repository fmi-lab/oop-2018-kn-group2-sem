#include <iostream>
using namespace std;

class Polynomial {
public:
  Polynomial() {
    power = 0;
    coefs = new double[power + 1];
    coefs[0] = 0;
  }

  Polynomial(const Polynomial& other) {
    doCopy(other);
  }

  Polynomial& operator=(const Polynomial& other) {
    if (this != &other) {
      doDelete();
      doCopy(other);
    }
    return *this;
  }

  ~Polynomial() {
    doDelete();
  }

  void print() const {
    for (int i = 0; i <= power; i++) {
      cout << coefs[i] << "*x^" << i << " + ";
    }
    cout << endl;
  }

  void set(int power, double value) {
    expandTo(power);
    coefs[power] = value;
  }

  double get(int power) const {
    if (power > this->power) {
      return 0;
    }
    return coefs[power];
  }

  Polynomial operator+(const Polynomial& other) const {
    Polynomial result;
    int n = max(this->power, other.power);
    for (int i = n; i >= 0; i--) {
      result.set(i, this->get(i) + other.get(i));
    }
    return result;
  }

private:
  void expandTo(int power) {
    if (power <= this->power) {
      return;
    }

    double * newCoefs = new double[power + 1];
    for (int i = 0; i <= this->power; i++) {
      newCoefs[i] = coefs[i];
    }

    for (int i = this->power + 1; i <= power; i++) {
      newCoefs[i] = 0;
    }

    delete[] this->coefs;
    this->coefs = newCoefs;
    this->power = power;
  }

  void doCopy(const Polynomial& other) {
    this->power = other.power;
    this->coefs = new double[this->power];
    for (int i = 0; i <= this->power; i++) {
      this->coefs[i] = other.coefs[i];
    }
  }

  void doDelete() {
    delete[] coefs;
  }

private:
  int power;
  double * coefs;
};


int main() {
  Polynomial p1;
  p1.set(2, 5);
  p1.set(0, 13);
  p1.set(3, 1);

  Polynomial p2; // x^4 + x^2
  p2.set(4, 1);
  p2.set(2, 1);

  p1.print();
  p2.print();

  Polynomial p3 = p1 + p2;
  p3.print();

  return 0;
}
