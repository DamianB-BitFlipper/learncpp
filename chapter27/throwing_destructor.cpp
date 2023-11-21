#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>

class ThrowingDestructor {
public:
  ThrowingDestructor() {};
  ~ThrowingDestructor() {
    throw std::runtime_error{ "Throwing in the Destructor!" };
  }
};

void randomThrow() {
  ThrowingDestructor td{};
    
  try {
    throw std::runtime_error{ "Random Throw" };
  } catch (const std::exception& e) {
    std::cerr << "Caught: " << e.what() << std::endl;
  }
}

int32_t main() {
  randomThrow();

  return 0;
}
