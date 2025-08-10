#include <iostream>

#include "tests/test_arithmetic.hpp"
#include "tests/test_logging.hpp"
#include "tests/test_read_data.hpp"
#include "tests/test_statistik.hpp"

int main() {
  TestReadData();
  TestStatistik();
  TestLogging();
  TestArithmetic();

  return 0;
}
