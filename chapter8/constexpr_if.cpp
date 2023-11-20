#include <iostream>
#include <cstdint>

int32_t main() {

  using std::cout;
  using std::endl;

  constexpr int32_t gravity{ 10 };

  switch (gravity) {
  case 9:
  case 10:
    int32_t x;
    x = 10;
    cout << "Life is OK! " << x << endl;
    break;
  default:
    x  = 11;
    cout << "Something is wrong! " << x << endl;
    break;
  }

  if constexpr (gravity == 11) {
    goto end;
  }

  int32_t y;
  y = 11;
  cout << "Never prints " << y << endl;

 end:

  cout << "Prints " << y << endl;

  do {
    cout << "Y is: " << y << endl;
  } while (--y >= 0);

  for (int32_t z{ 0 }, a{ 0 }; a++, z <= 10; z++) {
    cout << "Z is: " << z << endl;
    cout << "A is: " << a << endl;    
  }

  int x{};
  std::cin >> x;
  cout << "X is: " << x << endl;
  
  return 0;
}
