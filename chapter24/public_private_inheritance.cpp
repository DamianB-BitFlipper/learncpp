#include <iostream>
#include <cstdint>

class Base
{
public:
  int m_public{ 1 };
protected:
  int m_protected{ 2 };
private:
  int m_private{ 3 };
};

class D2 : private Base
{
public:
  int m_d2public{ 4 };
protected:
  int m_d2protected{ 5 };
private:
  int m_d2private{ 6 };
};

class D3 : public D2
{
public:
  int m_d3public{ 7 };

  D3() {
    //std::cout << m_public << m_d2public << m_protected << m_d2protected << std::endl;
    std::cout << m_d2public << m_d2protected << std::endl;
  }

protected:
  int m_d3protected{ 8 };
private:
  int m_d3private{ 9 };
};

int32_t main() {
  D3 d3{};

  // std::cout << d3.D2::Base::m_public << std::endl;
  // std::cout << static_cast<const Base&>(d3).m_public << std::endl;

  return 0;
}
