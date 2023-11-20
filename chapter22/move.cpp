#include <iostream>
#include <cstdint>
#include <utility>
#include <vector>

int32_t main() {
  using namespace std::literals;

  std::string s1{ "Damian"s };
  std::vector<std::string> vector(2);

  vector.push_back(s1);

  std::cout << "S1: " << s1 << std::endl;

  vector.push_back(std::move(s1));

  std::cout << "S1: " << s1 << std::endl;

  return 0;
}
