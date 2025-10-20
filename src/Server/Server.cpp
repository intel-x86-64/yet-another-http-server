#include "Server.h"
#include <iostream>
#include <stdexcept>

Server::Server() : jP("config.json"), pP(jP) {

  jP.start();

  try {
    port = jP.getPort();
  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }
}