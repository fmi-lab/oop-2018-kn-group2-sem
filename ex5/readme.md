Упражнение 5
===

# Задачи
1. class Polynomial

Interface:

```
main(){
  Polynomial p1;
  p1.set(2, 5); // x^2 = 5
  p1.set(0, 13); // +13
  p1.set(3, 1); // +x^3
  p1.print(); // x^3 + 5x^2 + 13
  p1.get(2); // 5

  Polynomial p2;
  p2.set(4, 1); // x^4 + x^2
  p2.set(2, 1);

  Polynomial p3 = p1 + p2;
  Polynomial p4 = p1 * 5;
  // p1.multiply(int)
  // Optional: 5*x^3 + 20*x^2 + 65;
  // Optional: p5 = p1.firstDerivative();
}
```
