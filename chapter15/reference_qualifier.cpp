#include <iostream>
#include <cstdint>
#include <cassert>

class Name {
public:

  explicit Name(std::string_view name) : m_name { name } {}

  static Name createName(int32_t i) {
    using namespace std::literals;
    std::string_view names[] = {"Bill"sv, "Bob"sv};

    assert(i >= 0 && i <= 1 && "Name index i may only be between 0 and 1.");

    return Name(names[i]);
  }

  const auto& getName() const &;
  auto getName() const &&;

private:
  std::string m_name{};

};

const auto& Name::getName() const & { 
  std::cout << "Lvalue" << std::endl;
  return m_name; 
}

auto Name::getName() const && { 
  std::cout << "Rvalue" << std::endl;
  return m_name; 
}

int32_t main() {

  Name name{ "Damian" };
  std::cout << name.getName() << std::endl;

  Name name2{ Name::createName(1) };
  std::cout << name2.getName() << std::endl;

  std::cout << Name::createName(0).getName() << std::endl;

  return 0;
}
