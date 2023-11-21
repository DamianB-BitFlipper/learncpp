#include <iostream>
#include <cstdint>

class Lifetime {
public:
  Lifetime() { std::cout << "Creating Lifetime" << std::endl; }
  ~Lifetime() { std::cout << "Destroying Lifetime" << std::endl; }
};

class Lifetime2 {
public:
  Lifetime2() { std::cout << "Creating Lifetime2" << std::endl; }
  ~Lifetime2() { std::cout << "Destroying Lifetime2" << std::endl; }
};

class A {
public:
  A(int x) : m_x{x} {
    if (x <= 0) {
      throw x; // Exception thrown here
    }
  }

private:
  int m_x;
};

class B : public Lifetime, public A, public Lifetime2 {
public:
  B(int x) try // note addition of try keyword here
    : Lifetime{}
    , A{ x }
    , Lifetime2{}
  {
  }
  catch (...) { // note this is at same level of indentation as the function itself
    // Exceptions from member initializer list or constructor body are caught here
    std::cerr << "Exception caught\n";

    throw; // rethrow the existing exception
  }
};

int throwingFn(int x) try {
  if (x <= 0) {
    throw x - 1;
  }

  return x;
} catch (int ex) {
  std::cout << "Caught ex: " << ex << std::endl;
  return ex;
}

int main() {
  try {
    B b{ -69 };
  } catch (int x)
  {
    std::cout << "Oops: " << x << std::endl;
  }

  int x{ throwingFn(-68) };
  std::cout << "Outside: " << x << std::endl;
}
