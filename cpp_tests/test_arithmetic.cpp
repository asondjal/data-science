#include "tests/test_arithmetic.hpp"

void TestArithmetic() {
  Arithmetic test1{10.00, 20.00};
  assert(test1.AddNumbers() == 30.00);
  assert(test1.SubtractNumbers() == -10.00);
  assert(test1.MultiplyNumbers() == 200.00);
  assert(test1.DivideNumbers() == 0.5000);

  Arithmetic test2{0.00, 0.00};
  assert(test2.MultiplyNumbers() == 0.0000);
  assert(std::isnan(test2.DivideNumbers()));
  std::cout << "Alle Tests für Arithmetic waren erfolgreich!" << std::endl;
}
