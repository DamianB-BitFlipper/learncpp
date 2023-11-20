#include <iostream>
#include <cstdint>
#include <memory>
#include <utility>

class Resource
{
public:
  Resource() { std::cout << "Resource acquired" << std::endl; }
  ~Resource() { std::cout << "Resource destroyed" << std::endl; }

  friend std::ostream& operator<<(std::ostream& out, const Resource&) {
    return out << "I am a resource!" << std::endl;
  }
};

std::unique_ptr<Resource> takeOwnership(std::unique_ptr<Resource> res) {
  std::cout << *res << std::endl;
  return res;
}

void useResource(Resource* res) {
  std::cout << *res << std::endl;
}

int32_t main() {
  auto res1{ std::make_unique<Resource>() };
  std::unique_ptr<Resource> res2{};

  std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
  std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

  res2 = std::move(res1);

  res2 = takeOwnership(std::move(res2));
  useResource(res2.get());

  std::cout << "res1 is " << (res1 ? "not null\n" : "null\n");
  std::cout << "res2 is " << (res2 ? "not null\n" : "null\n");

  return 0;
}
