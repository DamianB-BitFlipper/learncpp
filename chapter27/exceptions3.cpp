#include <iostream>
#include <cstdint>
#include <exception>
#include <stdexcept>

class OurException : public std::exception {
public:
  OurException(std::string_view errMsg) : m_errMsg{ errMsg } {}

  const char* what() const noexcept override {  return m_errMsg.c_str(); }

private:
  const std::string m_errMsg{};
};

void noExceptionIPromise(int x) noexcept {
  if (x == 0) {
    throw 0;
  }
}

int32_t main() {

  try {
    throw OurException{ "Something to throw" };
  } catch (const std::exception& e) {
    std::cout << "Caught: " << e.what() << std::endl;
  }

  try {
    noExceptionIPromise(0);
  } catch (int) {
    std::cout << "Caught an int" << std::endl;
  }

  return 0;
}
