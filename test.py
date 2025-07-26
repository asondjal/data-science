"""Einfaches Python-File zur Datenanalyse"""

from py_bindings import ReadData
from py_bindings import Statistik
from py_bindings import Logging, LogLevel


basic = ReadData("logfile.txt")
print(basic.read_auto())

statistics = Statistik()
statistics.lade_daten(basic)
print(statistics.wortanzahl())
print(statistics.zaehle_variable("DEBUG"))

logging = Logging("data-report.txt", LogLevel.INFO, True)
logging.start_log("File was modified", LogLevel.INFO)
