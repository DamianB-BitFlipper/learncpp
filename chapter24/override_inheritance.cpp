#include <iostream>
#include <cstdint>

class Base
{
public:
  Base(int value) : m_value { value } {}

  void identify() const { std::cout << "I am a Base" << std::endl; }

  friend std::ostream& operator<<(std::ostream& out, const Base& base) {
    return out << "Base: " << base.m_value;
  }

  int32_t m_public{ 69 };
  void printPublic() const { std::cout << "Base Public" << std::endl; }

  void toDelete() const { std::cout << "I should be deleted!" << std::endl; }

protected:
  const int m_value{};

  void printProtection() const { std::cout << "Base Protection" << std::endl; }
};

class Derived: public Base
{
public:
  Derived(int value) : Base { value } {}

  void identify() const { 
    Base::identify();
    std::cout << "I am a Derived" << std::endl; 
  }

  friend std::ostream& operator<<(std::ostream& out, const Derived& derived) {
    out << static_cast<const Base&>(derived) << std::endl;
    out << "Derived: " << derived.m_value;
    return out;
  }

  using Base::printProtection;

  int32_t getPublic() const { return m_public; }

  void toDelete() = delete;

private:
  using Base::m_public;
  using Base::printPublic;
};

int32_t main() {
  Base base{ 5 };
  base.identify();

  Derived derived{ 7 };
  derived.identify();
  // std::cout << "Derived m_public: " << derived.m_public << std::endl;
  std::cout << "Derived m_public: " << static_cast<const Base&>(derived).m_public << std::endl;
  std::cout << "Derived m_public: " << derived.getPublic() << std::endl;
  // derived.printPublic();
  derived.printProtection();

  // derived.toDelete();
  derived.Base::toDelete();
  static_cast<const Base&>(derived).toDelete();

  std::cout << base << std::endl;
  std::cout << derived << std::endl;

  return 0;
}
