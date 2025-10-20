#pragma once

#include "../JsonParser/JsonParser.h"
#include "../PageParser/PageParser.h"
#include <cstdint>
#include <sys/types.h>

class Server {
  JsonParser jP;
  PageParser pP;
  uint8_t port;

public:
  Server();
};