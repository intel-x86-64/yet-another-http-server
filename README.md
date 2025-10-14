
## TODO List

### Phase 1: Core Configuration & Basic Structures
- [ ] **Implementation of Config class for JSON configuration parsing**
  - [ ] Create Config class with fields: port, root directory, thread pool size, etc.
  - [ ] Integrate nlohmann/json library for parsing
  - [ ] Add configuration validation methods
  - [ ] Implement error handling for malformed JSON

- [ ] **Basic HTTP structures implementation**
  - [ ] Create Request class to represent HTTP requests
  - [ ] Create Response class to represent HTTP responses
  - [ ] Implement HTTP method enumeration (GET, POST, etc.)
  - [ ] Add HTTP status code constants

### Phase 2: Connection Handling & Routing
- [ ] **ConnectionHandler class implementation**
  - [ ] Create socket connection handling
  - [ ] Implement HTTP request parsing
  - [ ] Add response sending mechanism
  - [ ] Handle connection timeouts and errors

- [ ] **Router class implementation**
  - [ ] Create route registration system
  - [ ] Implement route matching algorithm
  - [ ] Add support for path parameters
  - [ ] Create default 404 handler

### Phase 3: Server Core & Static Content
- [ ] **HttpServer main class implementation**
  - [ ] Create server initialization with Config
  - [ ] Implement start/stop methods
  - [ ] Add thread pool management
  - [ ] Implement graceful shutdown

- [ ] **StaticFileHandler implementation**
  - [ ] Create file serving functionality
  - [ ] Implement MIME type detection
  - [ ] Add directory listing (optional)
  - [ ] Implement file caching mechanism

### Phase 4: Logging & Utilities
- [ ] **Logger class implementation**
  - [ ] Create log levels (DEBUG, INFO, WARN, ERROR)
  - [ ] Implement file and console logging
  - [ ] Add log rotation support

- [ ] **Utility functions**
  - [ ] Create string utility functions
  - [ ] Implement URL encoding/decoding
  - [ ] Add date/time formatting helpers

### Phase 5: Integration & Testing
- [ ] **Main application entry point**
  - [ ] Create main.cpp with server initialization
  - [ ] Implement signal handling for graceful shutdown
  - [ ] Add command line argument parsing

- [ ] **Configuration file setup**
  - [ ] Create example server_config.json
  - [ ] Add configuration documentation

- [ ] **Basic testing**
  - [ ] Create unit tests for Config class
  - [ ] Test HTTP request/response parsing
  - [ ] Verify static file serving

### Phase 6: Advanced Features & Optimization
- [ ] **Performance improvements**
  - [ ] Implement connection pooling
  - [ ] Add response compression
  - [ ] Optimize file reading

- [ ] **Security enhancements**
  - [ ] Add request size limits
  - [ ] Implement path traversal protection
  - [ ] Add basic security headers

### Phase 7: Documentation & Deployment
- [ ] **Project documentation**
  - [ ] Write comprehensive README
  - [ ] Add code documentation
  - [ ] Create API usage examples

- [ ] **Build system**
  - [ ] Create CMakeLists.txt
  - [ ] Add dependency management
  - [ ] Configure compiler flags

## Dependencies
- [ ] nlohmann/json library
- [ ] C++17 compatible compiler
- [ ] CMake 3.10+

## Development Notes
- Follow RAII principles for resource management
- Use smart pointers for memory management
- Implement copy/move semantics where appropriate
- Add comprehensive error handling
- Ensure thread safety for shared resources

Start with Phase 1 and proceed sequentially. Each phase builds upon the previous one, ensuring a solid foundation before adding complexity.
