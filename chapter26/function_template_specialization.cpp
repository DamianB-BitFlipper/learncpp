#include <iostream>
#include <cstdint>

template <typename T>
class Storage {
public:
  
  Storage(T value) : m_value{ value } {}
  // No Storage destructor defined fails compilation
  // ~Storage() = default; // Compiles but "Deleting double" never printed
  ~Storage() {}; // Compiles and "Deleting double" is printed

  void print() const { std::cout << m_value << std::endl; }

private:
  T m_value{};
};

template<>
Storage<double>::Storage(double value) : m_value{ value + 1} {}

template<>
Storage<double>::~Storage() { std::cout << "Deleting double" << std::endl; }

template<>
void Storage<double>::print() const {
  std::cout << std::scientific << m_value << std::endl;
}

int32_t main() {
  Storage s{ 7 };
  s.print();

  Storage d{ 7.0 };
  d.print();

  return 0;
}
