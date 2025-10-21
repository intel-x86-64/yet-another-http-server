#include "Server.h"
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
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

std::string Server::requestProcessing(std::string request) {
  std::istringstream stream(request);

  std::string method, path, protocol;
  stream >> method >> path >> protocol;

  return pageParser.parsePage(path);
}

void Server::handleClient(int clientSocket) {
  char buffer[1024]{0};
  ssize_t bytesRead = read(clientSocket, buffer, 1023);
  if (bytesRead < 0) {
    throw std::runtime_error("Error read buffer");
  }

  std::string request{buffer};
  std::string responce = requestProcessing(request);

  send(clientSocket, responce.c_str(), responce.size(), 0);
}

void Server::listenSocket() {
  if (listen(serverSocket, 3) == -1) {
    throw std::runtime_error("Error to listen socket");
  }

  while (true) {
    int clientSocket = accept(serverSocket, 0, 0);

    if (clientSocket < 0) {
      throw std::runtime_error("Error to accept client");
    }

    try {
      handleClient(clientSocket);
    } catch (const std::runtime_error &ex) {
      std::cerr << ex.what() << std::endl;
    }
  }
}

void Server::start() {
  this->setupAddress();
  try {
    this->createSocket();
    this->bindSocket();

  } catch (const std::runtime_error &ex) {
    std::cerr << ex.what() << std::endl;
  }

  this->listenSocket();
}

Server::~Server() {
  if (serverSocket >= 0) {
    close(serverSocket);
    std::cout << "The socket is closed" << std::endl << "Bye" << std::endl;
  }
}