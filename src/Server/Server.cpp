#include "Server.h"
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>

void Server::createSocket() {

  serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  if (serverSocket < 0) {
    throw std::runtime_error("error creating socket");
  }
}

void Server::bindSocket() {
  if (bind(serverSocket, reinterpret_cast<sockaddr *>(&address),
           sizeof(address)) < 0) {
    throw std::runtime_error("Binding error");
  }
}

void Server::setupAddress() {
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
}

Server::Server() : jsonParser("config.json"), pageParser(jsonParser) {
  try {
    jsonParser.start();
    port = jsonParser.getPort();

  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }
}

void Server::listenSocket() {}

void Server::start() {
  this->setupAddress();
  try {
    this->createSocket();
    this->bindSocket();

  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }
}

Server::~Server() {
  if (serverSocket >= 0) {
    close(serverSocket);
    std::cout << "The socket is closed" << std::endl << "Bye" << std::endl;
  }
}