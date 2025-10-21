#include "Server.h"
#include <iostream>
#include <stdexcept>

Server::Server() : jsonParser("config.json"), pageParser(jsonParser) {

  jsonParser.start();

  try {
    port = jsonParser.getPort();
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }
}