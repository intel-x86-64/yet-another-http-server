#include "PageParser.h"
#include <fstream>
#include <stdexcept>
#include <string>

PageParser::PageParser(JsonParser jp) { urls = jp.getPathToPages(); }

std::string PageParser::parsePage(std::string page) {
  std::ifstream file;
  file.open(urls[page]);

  if (!file.is_open()) {
    throw std::runtime_error("Unable to open " + urls[page]);
  }

  std::string returnPage, line;

  while (std::getline(file, line)) {
    returnPage += line;
  }

  file.close();

  return returnPage;
}
