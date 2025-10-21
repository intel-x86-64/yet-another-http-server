#pragma once

#include "../JsonParser/JsonParser.h"
#include <string>

class PageParser {
  std::map<std::string, std::string> urls;

public:
  PageParser();
  PageParser(JsonParser jp);
  std::string parsePage(std::string page);
};