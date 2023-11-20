#include <iostream>
#include <cstdint>

template <typename T>
T& max(T& a, T& b) {
  return (a > b) ? a : b;
}

const std::string& maxStr(std::string& a, std::string& b) {
  return (a > b) ? a : b;
}

int32_t main() {
  int a{ 69 };
  int b{ 420 };

  max(a, b) = 11;
  
  std::cout << "A: " << a << " B: " << b << std::endl;

  std::string as{ "bar" };
  std::string bs{ "foo" };

  auto& maxs{ maxStr(as, bs) };

  std::cout << "A: " << as << " B: " << bs << std::endl;
  std::cout << "Max: " << maxs << std::endl;
  
  return 0;
}
