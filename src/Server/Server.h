#pragma once

#include "../JsonParser/JsonParser.h"
#include "../PageParser/PageParser.h"
#include <cstdint>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

class Server {
  JsonParser jsonParser;
  PageParser pageParser;
  uint8_t port;
  int serverSocket;
  sockaddr_in address;

  void createSocket(int port);
  void bindSocket();

public:
  Server();

  ~Server();
};