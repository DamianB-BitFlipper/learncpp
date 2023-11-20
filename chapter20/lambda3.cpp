#include <iostream>
#include <cstdint>
#include <functional>

void myInvoke(const std::function<void()>& fn) {
  fn();
}

int32_t main() {

  int32_t i{ 0 };

  auto count = 
    [i]() mutable {
      i++;
      std::cout << "count: " << i << std::endl;
    };

  myInvoke(std::ref(count));
  myInvoke(std::ref(count));
  myInvoke(std::ref(count));

  std::cout << "I: " << i << std::endl;

  return 0;
}
