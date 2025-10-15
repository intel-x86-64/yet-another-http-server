#include "JsonParser.h"
#include <fstream>
#include <stdexcept>
#include <string>

JsonParser::JsonParser(const std::string configFilePath)
    : configFilePath(configFilePath) {}

std::string JsonParser::getConfigText() {
  std::string line;
  std::ifstream file("config.json");

  if (!file.is_open()) {
    throw std::runtime_error("Configuration " + configFilePath + " not open");
  }

  if (file.tellg() == 0) {
    throw std::runtime_error("Configuration is empty");
  }

  while (std::getline(file, line)) {
    configText += line + "\n";
  }

  file.close();
}