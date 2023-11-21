#include <iostream>
#include <cstdint>
#include <string_view>
#include <string>

void someFunction() {
  using namespace std::string_view_literals;
  throw "Exception"sv;
}

int32_t main() {
  try {
    someFunction();
  } catch (int) {
    std::cout << "Caught an int" << std::endl;

  } catch (std::string) {
    std::cout << "Caught a string" << std::endl;

  } catch (std::string_view) {
    std::cout << "Caught a string view" << std::endl;
  }

  return 0;
}
