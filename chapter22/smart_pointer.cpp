#include <iostream>
#include <cstdint>

template <typename T>
class AutoPtr {
public:

  AutoPtr(T* ptr=nullptr) : m_ptr{ ptr } {}

  ~AutoPtr() {
    delete m_ptr;
  }

  AutoPtr(AutoPtr& other) {
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;
  }

  AutoPtr& operator=(AutoPtr& other) {
    if (this == &other) {
      return *this;
    }

    delete m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = nullptr;

    return *this;
  }

  T& operator*() const { return *m_ptr; }
  T* operator->() const { return m_ptr; }

  bool isNull() const { return m_ptr == nullptr; }

private:
  T* m_ptr{};
};

class ResourcePrinter {
public:
  ResourcePrinter() {
    std::cout << "Creating Resource" << std::endl;
  }

  ~ResourcePrinter() {
    std::cout << "Destroying Resource" << std::endl;    
  }

  void sayHi() const {
    std::cout << "Hi from the Resource Printer" << std::endl;
  }
};

int32_t main() {
  AutoPtr autoPtr{ new (std::nothrow) ResourcePrinter{} };
  AutoPtr<ResourcePrinter> autoPtr2{};

  int age{};
  std::cout << "Enter your age" << '\n';
  std::cin >> age;

  if (!age) {
    return 0;
  }

  std::cout << "autoPtr is " << (autoPtr.isNull() ? "null\n" : "not null\n");
  std::cout << "autoPtr2 is " << (autoPtr2.isNull() ? "null\n" : "not null\n");

  // Move semantics
  autoPtr2 = autoPtr;

  autoPtr2->sayHi();

  std::cout << "autoPtr is " << (autoPtr.isNull() ? "null\n" : "not null\n");
  std::cout << "autoPtr2 is " << (autoPtr2.isNull() ? "null\n" : "not null\n");

  return 0;
}
