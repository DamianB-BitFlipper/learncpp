#include <iostream>
#include <cstdint>
#include <sstream>
#include <vector>
#include <cassert>

int32_t fibonacci(int32_t count) {
  static std::vector<int32_t> results{ 0, 1 };

  if (count <= static_cast<int32_t>(results.size())) {
    std::cout << "Cache" << std::endl;
    // Account for 1-indexing of `count`
    return results[count - 1];
  }

  std::cout << "Computing" << std::endl;

  // We need to grow the `fibonacci` vector up to `count`
  while (count > static_cast<int32_t>(results.size())) {
    const int32_t ultimate{ results.back() };
    const int32_t penultimate{ *(results.end() - 2) };
  
    results.push_back(ultimate + penultimate);
  }

  // Account for 1-indexing of `count`
  return results[count - 1];
}

int32_t main(const int argc, const char* argv[]) {
  assert(argc == 2 && "Enter 1 CLI argument.");

  std::stringstream convert{ argv[1] };
  int32_t n{};
  if (!(convert >> n)) {
    std::cout << "Failed to convert: " << argv[1] << std::endl;
    // Default value if conversion fails
    n = 1;
  }

  for (int32_t i{ n }; i > 0; --i) {
    std::cout << fibonacci(i) << std::endl;
  }

  return 0;
}
