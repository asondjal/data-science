#include "utils/read_data.hpp"

ReadData::ReadData(const std::string& path) : filePath_{path} {}

std::mutex& ReadData::GetMutex() { return mtx_; }

std::string ReadData::GetFileType(const std::string& location) const {
  std::string fileType = std::filesystem::path(location).extension().string();
  return fileType;
}

/**
 * @brief Liest den Inhalt einer Datei aus und gibt ihn als String zurück
 * @return Inhalt der Datei als String
 */
std::string ReadData::ReadFile() const {
  std::lock_guard<std::mutex> lock(mtx_);  // Schutz vor Race Conditions
  if (!std::filesystem::exists(filePath_)) {
    throw std::runtime_error("Nicht existierende Datei: " + filePath_);
  }

  std::ifstream file(filePath_);
  if (!file.is_open()) {
    throw std::runtime_error("Fehler beim Öffnen der Datei: " + filePath_);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  is_cached_ = true;
  cache_ = buffer.str();

  return buffer.str();
}

/**
 * @brief Liest den Inhalt einer Textdatei aus und gibt ihn als String zurück
 * @return Inhalt der Text-Datei als String
 */
std::string ReadData::ReadTxt() const {
  if (GetFileType(filePath_) != ".txt") {
    throw std::runtime_error("Dateiformat anstatt .txt: " +
                             std::filesystem::path(filePath_).extension().string());
  }
  return ReadFile();
}

/**
 * @brief Liest den Inhalt einer CSV-Datei aus und gibt ihn als String zurück
 * @return Inhalt der CSV-Datei als String
 */
std::string ReadData::ReadCSV() const {
  if (GetFileType(filePath_) != ".csv") {
    throw std::runtime_error("Dateiformat anstatt .csv: " +
                             std::filesystem::path(filePath_).extension().string());
  }
  return ReadFile();
}

/**
 * @brief Liest den Inhalt einer JSON-Datei und gibt ihn als String zurück
 * @return Inhalt der JSON-Datei als String
 */
std::string ReadData::ReadJSON() const {
  if (GetFileType(filePath_) != ".json") {
    throw std::runtime_error("Dateiformat anstatt .json: " +
                             std::filesystem::path(filePath_).extension().string());
  }
  return ReadFile();
}

/**
 * @brief Liest den Inhalt einer PDF-Datei und gibt ihn als String zurück
 * @return Inhalt der PDF-Datei als String
 */
std::string ReadData::ReadPDF() const {
  std::string content;
  std::lock_guard<std::mutex> lock(mtx_);

  if (GetFileType(filePath_) != ".pdf") {
    throw std::runtime_error("Dateiformat anstatt .pdf: " +
                             std::filesystem::path(filePath_).extension().string());
  }

  poppler::document* doc = poppler::document::load_from_file(filePath_);

  if (!doc) {
    throw std::runtime_error("PDF-Datei kann nicht geöffnet werden: " + filePath_);
  }
  for (int i = 0; i < doc->pages(); ++i) {
    poppler::page* p = doc->create_page(i);
    if (p) {
      content += p->text().to_latin1();
      delete p;
    }
  }
  delete doc;
  return content;
}

/**
 * @brief Liest den Inhalt einer HTML-Datei aus und gibt ihn als String zurück
 */
std::string ReadData::ReadHTML() const {
  if (GetFileType(filePath_) != ".html") {
    throw std::runtime_error("Dateiformat anstatt .html: " +
                             std::filesystem::path(filePath_).extension().string());
  }
  return ReadFile();
}

/**
 * @brief Liest den Inhalt einer XML-Datei aus und gibt den Inhalt als String zurück
 */
std::string ReadData::ReadXML() const {
  std::lock_guard<std::mutex> lock(mtx_);
  tinyxml2::XMLDocument doc;

  if (GetFileType(filePath_) != ".xml") {
    throw std::runtime_error("Dateiformat anstatt .xml: " +
                             std::filesystem::path(filePath_).extension().string());
  }

  if (doc.LoadFile(filePath_.c_str()) != tinyxml2::XML_SUCCESS) {
    throw std::runtime_error("Fehler beim Laden der XML-Datei: " + filePath_);
  }

  tinyxml2::XMLPrinter printer;
  doc.Print(&printer);

  cache_ = printer.CStr();
  is_cached_ = true;
  return cache_;
}

/**
 * @brief Liest den Inhalt einer Datei basierend auf der Dateiendung aus
 * @return Inhalt der Datei als String
 */
std::string ReadData::ReadAuto(bool reload) const {
  if (!reload && is_cached_) {
    return cache_;
  }

  auto ext = std::filesystem::path(filePath_).extension().string();
  std::string content;

  if (ext == ".txt") {
    content = ReadTxt();
  } else if (ext == ".csv") {
    content = ReadCSV();
  } else if (ext == ".json") {
    content = ReadJSON();
  } else if (ext == ".pdf") {
    content = ReadPDF();
  } else if (ext == ".html") {
    content = ReadHTML();
  } else if (ext == ".xml") {
    content = ReadXML();
  }

  else {
    throw std::runtime_error("Unbekanntes Dateiformat: " + ext);
  }

  cache_ = content;
  is_cached_ = true;
  return cache_;
}

/**
 * @brief Wiedergabe der im Buffer gespeicherten Informationen
 * @param bool print, `true` per Default, sonst `false`
 */
std::vector<std::string> ReadData::DisplayData() const {
  std::lock_guard<std::mutex> lock(mtx_);

  if (!is_cached_) {
    throw std::runtime_error("Der Cache ist leer. Bitte laden Sie Daten!");
  }

  std::vector<std::string> lines;
  std::istringstream stream(cache_);
  std::string line;
  int line_number = 1;

  while (std::getline(stream, line)) {
    lines.push_back(line);
    std::cout << "[Zeile " << line_number << ": \"" << line << "\"]" << std::endl;
    ++line_number;
  }

  return lines;
}

/**
 * @brief Speicherverwaltung vom Cache --> Muss noch getestet werden!!
 */
void ReadData::ObserveCache() const {
  std::lock_guard<std::mutex> lock(mtx_);
  cache_.clear();
  is_cached_ = false;
}
