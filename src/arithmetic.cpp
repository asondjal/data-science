#include "utils/arithmetic.hpp"

Arithmetic::Arithmetic(float eingabe1, float eingabe2) : eingabe1_{eingabe1}, eingabe2_{eingabe2} {}

float Arithmetic::AddNumbers() const { return eingabe1_ + eingabe2_; }

float Arithmetic::SubtractNumbers() const { return eingabe1_ - eingabe2_; }

float Arithmetic::MultiplyNumbers() const {
  std::cout << std::setprecision(4) << std::endl;
  return eingabe1_ * eingabe2_;
}

float Arithmetic::DivideNumbers() const {
  std::cout << std::setprecision(4) << std::endl;

  if (eingabe2_ == 0.0f) {
    if (eingabe1_ == 0.0f) {
      return std::numeric_limits<float>::quiet_NaN();
    } else {
      return std::numeric_limits<float>::infinity();
    }
  }

  return eingabe1_ / eingabe2_;
}
