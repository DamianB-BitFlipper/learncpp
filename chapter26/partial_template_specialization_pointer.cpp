#include <iostream>
#include <cstdint>

template <typename T>
class Storage {
public:

  Storage(T value) : m_value{ value } {}

  void print() const {
    std::cout << m_value << std::endl;
  }

private:
  T m_value{};
};

template <typename T>
class Storage<T*> {
public:

  Storage(T* value) : m_value{ new T { *value } } {}

  ~Storage() {
    std::cout << "Deleting" << std::endl;
    delete m_value;
  }

  void print() const {
    std::cout << m_value << std::endl;
  }

  Storage(const Storage&) = delete;
  Storage& operator=(const Storage&) = delete;

private:
  T* m_value{};
};

int32_t main() {
  int32_t x{ 10 };
  Storage s1{ &x };

  return 0;
}
