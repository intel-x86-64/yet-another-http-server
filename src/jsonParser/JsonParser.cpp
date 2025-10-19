#include "JsonParser.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <stdexcept>
#include <string>

JsonParser::JsonParser(const std::string configFilePath)
    : configFilePath(configFilePath) {}

void JsonParser::parseConfigFromFile() {
  std::string line;
  std::ifstream file("config.json");

  if (!file.is_open()) {
    throw std::runtime_error("Configuration " + configFilePath + " not open");
  }

  //   if (file.tellg() == 0) {
  //     throw std::runtime_error("Configuration is empty");
  //   }

  config = nlohmann::json::parse(file);

  file.close();
}

void JsonParser::parseUrls() {
  if (!config.contains("Urls")) {
    throw std::runtime_error(
        "There are no links to pages in the configuration");
  }

  if (!config["Urls"].is_object()) {
    throw std::runtime_error("Syntax error in page link configuration");
  }

  for (auto &[key, value] : config["Urls"].items()) {
    urls.emplace(key, value);
  }
}

void JsonParser::start() {
  try {
    this->parseConfigFromFile();
  } catch (const std::runtime_error &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }

  try {
    this->parseUrls();
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }
}

int JsonParser::getPort() {
  if (!config.contains("port")) {
    throw std::runtime_error("config.json does not contain a port");
  }

  return config["port"];
}
