#include <iostream>
#include <cstdint>

int32_t main() {
  int32_t prefix1{ 69 };
  int32_t prefix2{ 420 };

  auto print{
    [=, &prefix1, sum{ prefix1 + prefix2 } ](auto value) mutable { 
      static int i{ 0 };
      prefix1++;
      prefix2--;
      sum += 1000;

      std::cout << sum << ' ' << prefix1 << ' ' << prefix2 << " : Value: " << value << " : " << i << std::endl; 
      i++;
    }
  };

  print("A");
  print("B");

  print(1);
  print(2);

  std::cout << prefix1 << std::endl;
  std::cout << prefix2 << std::endl;

  return 0;
}
