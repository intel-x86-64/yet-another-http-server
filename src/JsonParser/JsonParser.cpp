#include "JsonParser.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <ostream>
#include <stdexcept>
#include <string>

JsonParser::JsonParser(const std::string configFilePath)
    : configFilePath(configFilePath) {
  std::cout << "[INFO] [JSON PARSER CLASS] JsonParser constructor" << std::endl;
  this->start();
}

void JsonParser::parseConfigFromFile() {
  std::string line;
  std::ifstream file("config.json");

  if (!file.is_open()) {
    throw std::runtime_error("Configuration " + configFilePath + " not open");
  }

  std::cout << "[INFO] [JSON PARSER CLASS] open " + configFilePath << std::endl;

  //   if (file.tellg() == 0) {
  //     throw std::runtime_error("Configuration is empty");
  //   }

  config = nlohmann::json::parse(file);

  file.close();

  std::cout << "[INFO] [JSON PARSER CLASS] " + configFilePath + " close"
            << std::endl;
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
    std::cout << "[INFO] [JSON PARSER CLASS] add " << key << " : " << value
              << " to urls" << std::endl; // log
  }
}

std::map<std::string, std::string> JsonParser::getPathToPages() {
  std::cout << "[METHOD] getPathToPages" << std::endl; // log
  for (auto &[key, value] : urls) {
    std::cout << key << " : " << value << std::endl; // log
  }
  return urls;
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
