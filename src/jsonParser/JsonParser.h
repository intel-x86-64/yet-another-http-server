#pragma ONCE

#include <fstream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <string>

class JsonParser {
  std::string configFilePath;
  std::string configText;

public:
  JsonParser(const std::string configFilePath);
};