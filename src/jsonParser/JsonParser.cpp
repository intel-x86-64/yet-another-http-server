#include "JsonParser.h"
#include <fstream>
#include <string>

JsonParser::JsonParser(const std::string configFilePath)
    : configFilePath(configFilePath) {}