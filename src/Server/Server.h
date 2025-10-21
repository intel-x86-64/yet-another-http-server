#pragma once

#include "../JsonParser/JsonParser.h"
#include "../PageParser/PageParser.h"
#include <cstdint>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>

class Server {
  JsonParser jsonParser;
  PageParser pageParser;
  uint16_t port;
  int serverSocket;
  sockaddr_in address;

  void setupAddress();
  void createSocket();
  void bindSocket();
  void listenSocket();
  void handleClient(int clientSocket);
  std::string requestProcessing(std::string request);

public:
  Server();
  void start();
  ~Server();
};