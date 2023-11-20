#include <iostream>
#include <cstdint>

#include "do_something11.h"

namespace One {
  
  int32_t doSomething(int32_t a) {
    namespace Active = Const;

    {
      uint32_t a{ 100 };
      std::cout << "A is " << a << std::endl;
    }
    
    return a % Active::crazy == 0;
  }
  
}
