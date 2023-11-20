#include <iostream>
#include <cstdint>
#include <memory>

class Resource
{
public:
  Resource() { std::cout << "Resource acquired" << std::endl; }
  ~Resource() { std::cout << "Resource destroyed" << std::endl; }
};

int32_t main() {
  std::shared_ptr<Resource> ptr1{ std::make_shared<Resource>() };
  {
    std::shared_ptr<Resource> ptr2{ ptr1 };

    std::cout << "Killing one shared pointer" << std::endl;
  }

  std::cout << "Killing the other shared pointer" << std::endl;

  return 0;
}
