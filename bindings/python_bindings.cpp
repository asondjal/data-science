#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "utils/statistik.hpp"
#include "utils/logging.hpp"
#include <memory>

namespace py = pybind11;

PYBIND11_MODULE(py_bindings, py_module) {
    py::class_<ReadData>(py_module, "ReadData")
        .def(py::init<const std::string&>())
        .def("read_txt", &ReadData::ReadTxt)
        .def("read_csv", &ReadData::ReadCSV)
        .def("read_json", &ReadData::ReadJSON)
        .def("read_pdf", &ReadData::ReadPDF)
        .def("read_auto", &ReadData::ReadAuto)
        .def("read_html", &ReadData::ReadHTML)
        .def("read_xml", &ReadData::ReadXML)
        .def("display_data", &ReadData::DisplayData);

    py::class_<Statistik>(py_module, "Statistik")
        .def(py::init<>())
        .def("lade_daten", &Statistik::LadeDaten)
        .def("entferne_daten", &Statistik::EntferneDaten)
        .def("zaehle_eintraege", &Statistik::ZaehleEintraege)
        .def("zeichenanzahl", &Statistik::ZaehleZeichen)
        .def("wortanzahl", &Statistik::ZaehleWorte)
        .def("zaehle_linen", &Statistik::ZaehleLinien)
        .def("zaehle_variable", &Statistik::ZaehleVariable)
        .def("mittelwert", &Statistik::Mittelwert)
        .def("median", &Statistik::Median)
        .def("erwartungswert", &Statistik::Erwartungswert)
        .def("standardabweichung", &Statistik::Standardabweichung);

    py::enum_<LogLevel>(py_module, "LogLevel")
        .value("DEBUG", LogLevel::DEBUG)
        .value("INFO", LogLevel::INFO)
        .value("WARNING", LogLevel::WARNING)
        .value("ERROR", LogLevel::ERROR)
        .export_values();

    py::class_<Logging>(py_module, "Logging")
        .def(py::init<const std::string&, LogLevel, bool>())
        .def("start_log", &Logging::Log)
        .def("set_loglevel", &Logging::SetLevel)
        .def("enable_console_output", &Logging::EnableConsoleOutput)
        .def("get_level", &Logging::GetLevel);
}
