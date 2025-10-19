#pragma ONCE

#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <string>

class JsonParser {
  std::string configFilePath;
  nlohmann::json config;

  void parseConfigFromFile();

public:
  JsonParser(const std::string configFilePath);
  int getPort();
  void start();
};
