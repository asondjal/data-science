#ifndef INC_UTILS_ARITHMETIC_HPP_
#define INC_UTILS_ARITHMETIC_HPP_

#include <cinttypes>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

class Arithmetic {
 private:
  const float eingabe1_;
  const float eingabe2_;

 public:
  Arithmetic(float eingabe1, float eingab2);
  float AddNumbers() const;
  float SubtractNumbers() const;
  float MultiplyNumbers() const;
  float DivideNumbers() const;
};

#endif  // INC_UTILS_ARITHMETIC_HPP_
