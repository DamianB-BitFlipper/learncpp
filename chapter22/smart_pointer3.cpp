#include <iostream>
#include <cstdint>
#include <utility>

class Name {
public:

  Name(std::string_view name) : m_name{ name } {}

  Name(const Name&) = delete;
  Name& operator=(const Name&) = delete;

  Name(Name&& other) {
    std::cout << "Move constr" << std::endl;
    m_name = std::move(other.m_name);
  }
  Name& operator=(Name&& other) {
    std::cout << "Move =" << std::endl;
    m_name = std::move(other.m_name);
    return *this;
  }

  std::string_view getName() const { return m_name; }

private:
  std::string m_name{};
};

Name generateName() {
  using namespace std::literals;
  Name ret{ "Joe Billy"sv };
  return ret;
}

int32_t main() {
  Name name{ "Damian" };
  Name name2 { std::move(generateName()) };

  std::cout << name.getName() << std::endl;
  std::cout << name2.getName() << std::endl;

  return 0;
}
