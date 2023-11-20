#include <functional>
#include <iostream>
#include <cstdint>
#include <string_view>
#include <vector>

class Base {
public:
  Base(int value) : m_value{ value } {}
  virtual ~Base() = default;

  virtual std::string_view getName() const { return "Base"; }
  int getValue() const { return m_value; }

protected:
  int m_value{};
};

class Derived: public Base {
public:
  Derived(int value) : Base{ value } {}

  std::string_view getName() const override { return "Derived"; }
};

int main()
{
  Derived derived{ 5 };
  std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << std::endl;

  Base& ref{ derived };
  std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << std::endl;

  Base* ptr{ &derived };
  std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << std::endl;

  Base copy{ derived };
  std::cout << "ref is a " << copy.getName() << " and has value " << copy.getValue() << std::endl;

  std::vector<std::reference_wrapper<Base> > vector{};
  vector.push_back(derived);
  vector.push_back(ref);
  vector.push_back(copy);

  // Print out all of the elements in our vector
  for (const auto& element : vector) {
    std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';
  }
  
  return 0;
}
