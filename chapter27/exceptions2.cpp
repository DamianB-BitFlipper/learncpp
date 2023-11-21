#include <iostream>
#include <cstdint>

class Lifetime2 {
public:
  Lifetime2() {
    std::cout << "Created Lifetime2" << std::endl;
  }

  ~Lifetime2() {
    std::cout << "Destroyed Lifetime2" << std::endl;
  }
};

class Lifetime {
public:
  Lifetime() {
    std::cout << "Created Lifetime" << std::endl;
  }

  ~Lifetime() {
    std::cout << "Destroyed Lifetime" << std::endl;
  }

private:
  const Lifetime2 lt2{};
};

class Base {
public:
  
  Base(int32_t value) : m_value{ value } {}
  virtual ~Base() {}

  void print() const { std::cout << m_value << std::endl; }

  virtual void throwException() const;

private:
  const int32_t m_value{};
};

void Base::throwException() const {
  throw this;  
}

class Derived : public Base {
public:
  
  Derived(int32_t value) : Base{ value + 1 } {}

  void throwException() const override {
    const Derived& ref = *this;
    throw ref;
  }

};

void callException(const Base& base) {
  Lifetime lt{};

  base.throwException();
}

int32_t main() {
  Base base{ 69 };
  Derived derived{ 69 };

  base.print();
  derived.print();

  try {
    callException(derived);
  } catch (const Derived&) {
    std::cout << "Caught Derived&" << std::endl;
  } catch (const Derived*) {
    std::cout << "Caught Derived*" << std::endl;
  } catch (const Base&) { 
    std::cout << "Caught Base&" << std::endl;   
  } catch (const Base*) {
    std::cout << "Caught Base*" << std::endl;
  } catch (...) {
    std::cout << "Caught Something" << std::endl;    
  }

  return 0;
}
