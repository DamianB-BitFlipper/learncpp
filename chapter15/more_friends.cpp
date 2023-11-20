#include <iostream>
#include <cstdint>

class Storage;

class Printer {
public:
  
  explicit Printer(std::string_view prefix) : m_prefix{ prefix } {}

  void print(const Storage& storage) const;

private:
  std::string_view m_prefix{};
};

class Storage {
public:

  explicit Storage(int32_t n) : m_num { n } {}

  friend void Printer::print(const Storage& storage) const;

private:  
  int32_t m_num{};
};

void Printer::print(const Storage& storage) const {
  std::cout << m_prefix << std::endl;
  std::cout << "Storage: " << storage.m_num << std::endl;
}

int32_t main() {

  Storage storage{ 69 };
  Printer printer{ "yolo" };

  printer.print(storage);

  return 0;
}
