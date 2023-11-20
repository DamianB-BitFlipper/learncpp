#include <iostream>
#include <cstdint>

#include "do_something1.h"
#include "do_something2.h"

using std::cout;
using std::endl;

inline namespace a {
	 
  namespace {
    int32_t x { 6 };
  }

}

namespace b {

  int32_t x { 9 };

}

int32_t g_incr { 1 };
  
int32_t doSomething(int32_t a) {
  return a + g_incr;
}

int32_t main() {
  int32_t g_incr { 2 };
  
  cout << "Doing something One: " << One::doSomething(g_incr) << endl;
  cout << "Doing something Two: " << Two::doSomething(g_incr) << endl;

  ++(::g_incr);
  cout << "Doing something Global: " << ::doSomething(g_incr) << endl;    

  cout << "Linkage is " << Two::linkage << endl;

  cout << "X is " << a::x << endl;
  
  return 0;
}
