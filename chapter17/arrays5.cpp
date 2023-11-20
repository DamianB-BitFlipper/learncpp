#include <iostream>
#include <cstdint>

int32_t main() {
  constexpr int32_t arr[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

  const int32_t* ptr{ arr };
  const int32_t* end{ arr + std::size(arr) };

  for (; ptr != end; ptr++) {
    std::cout << *ptr << std::endl;
  }

  const char* const name{ "Damian" };

  std::cout << name << std::endl;

  return 0;
}
