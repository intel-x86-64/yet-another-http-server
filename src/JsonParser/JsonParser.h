#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <string>

class JsonParser {
  std::string configFilePath;
  nlohmann::json config;
  std::map<std::string, std::string> urls;

  void parseConfigFromFile();
  void parseUrls();

public:
  JsonParser();
  JsonParser(const std::string configFilePath);
  int getPort();
  std::map<std::string, std::string> getPathToPages();
  void start();
};
