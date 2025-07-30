#include "tests/test_logging.hpp"

void TestLogging() {
  Logging logger("logfile.txt", LogLevel::DEBUG);
  assert(std::filesystem::exists("logfile.txt"));
  assert(logger.GetLevel() == "DEBUG");
  logger.EnableConsoleOutput(true);
  assert(logger.TestConsoleStatus() == true);
  logger.TestGetTimestamp();
  logger.Log("System initialized.", LogLevel::INFO);
  logger.Log("Reading configuration...", LogLevel::DEBUG);
  logger.Log("File not found!", LogLevel::WARNING);
  logger.Log("Critical error!", LogLevel::ERROR);

  std::cout << "Alle Logging-Tests waren erfolgreich!" << std::endl;
}
