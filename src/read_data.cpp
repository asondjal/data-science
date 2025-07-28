#include "utils/read_data.hpp"

ReadData::ReadData(const std::string& path) : filePath_{path} {}

std::mutex& ReadData::GetMutex() { return mtx_; }

/**
 * @brief Speicherverwaltung vom Cache --> Muss noch implementiert werden!!
 */
void ReadData::InvalidateCache() const {
  is_cached_ = false;
  cache_.clear();
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
  return buffer.str();
}

/**
 * @brief Liest den Inhalt einer Textdatei aus und gibt ihn als String zurück
 * @return Inhalt der Text-Datei als String
 */
std::string ReadData::ReadTxt() const { return ReadFile(); }

/**
 * @brief Liest den Inhalt einer CSV-Datei aus und gibt ihn als String zurück
 * @return Inhalt der CSV-Datei als String
 */
std::string ReadData::ReadCSV() const { return ReadFile(); }

/**
 * @brief Liest den Inhalt einer JSON-Datei und gibt ihn als String zurück
 * @return Inhalt der JSON-Datei als String
 */
std::string ReadData::ReadJSON() const { return ReadFile(); }

/**
 * @brief Liest den Inhalt einer PDF-Datei und gibt ihn als String zurück
 * @return Inhalt der PDF-Datei als String
 */
std::string ReadData::ReadPDF() const {
  std::string content;
  std::lock_guard<std::mutex> lock(mtx_);
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
std::string ReadData::ReadHTML() const { return ReadFile(); }

/**
 * @brief Liest den Inhalt einer XML-Datei aus und gibt den Inhalt als String zurück
 */
void ReadData::ReadXML() {
  tinyxml2::XMLDocument doc;
  auto result = doc.LoadFile(filePath_.c_str());

  if (result != tinyxml2::XML_SUCCESS) {
    throw std::runtime_error("Fehler beim Laden der XML-Datei: " + filePath_);
  }

  tinyxml2::XMLElement* root = doc.RootElement();
  if (root) {
    std::cout << "Root-Element: " << root->Name() << std::endl;
  }
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
