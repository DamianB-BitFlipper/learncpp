#include <iostream>
#include <cstdint>

template <typename T>
class Storage8 {
public:

  Storage8() {
    std::cout << "Big representation" << std::endl;
  }

private:
  T m_data[8]{};
};

template<>
class Storage8<bool> {
public:

  Storage8() {
    std::cout << "Packed representation" << std::endl;
  }

  void printBool() const;

private:
  uint8_t m_data{};
};

void Storage8<bool>::printBool() const {
  std::cout << "Bool" << std::endl; 
}

int32_t main() {
  Storage8<int32_t> s1{};
  Storage8<bool> s2{};

  s2.printBool();

  return 0;
}
