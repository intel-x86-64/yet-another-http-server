#include "JsonParser.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

JsonParser::JsonParser(const std::string configFilePath)
    : configFilePath(configFilePath) {}

void JsonParser::getConfigText() {
  std::string line;
  std::ifstream file("config.json");

  if (!file.is_open()) {
    throw std::runtime_error("Configuration " + configFilePath + " not open");
  }

  //   if (file.tellg() == 0) {
  //     throw std::runtime_error("Configuration is empty");
  //   }

  while (std::getline(file, line)) {
    configText += line + "\n";
  }

  file.close();
}

void JsonParser::start() {
  try {
    this->getConfigText();
  } catch (const std::runtime_error &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }
}
