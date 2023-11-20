#include <iostream>
#include <cstdint>
#include <string>
#include <string_view>

#include "min.h"

consteval int32_t returnX(int32_t x) {
  return x;
}

void print_my_name_is(std::string_view name) {
  std::cout << "My name is: " << name << std::endl;
}

std::string_view get_bool_name(bool b) {
  return b ? "true" : "false";
}

int32_t main() {
  const int32_t x { 3 };
  
  const int32_t y { returnX(x) };

  float z { 31'415e-4f };
  
  std::cout << y << " " << z << std::endl;

  std::cout << min(4, 5) << std::endl;

  std::string name{};
  std::getline(std::cin >> std::ws, name);

  std::string_view name_view { name };
  name_view.remove_prefix(1);
  name_view.remove_suffix(2);
  
  print_my_name_is(name_view);

  constexpr std::string_view last_name { "Barabonkov" };
  print_my_name_is(last_name);

  std::cout << get_bool_name(true) << std::endl;

  return 0;
}
