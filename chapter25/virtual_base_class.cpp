#include <iostream>
#include <cstdint>

class PoweredDevice {
public:
  PoweredDevice(int power) {
    std::cout << "PoweredDevice: " << power << std::endl;
  }
};

class Scanner : virtual public PoweredDevice {
public:
  Scanner(int scanner, int power) : PoweredDevice{ power } {
    std::cout << "Scanner: " << scanner << std::endl;
  }
};

class Printer : virtual public PoweredDevice {
public:
  Printer(int printer, int power) : PoweredDevice{ power } {
    std::cout << "Printer: " << printer << std::endl;
  }
};

class Copier : public Scanner, public Printer {
public:
  Copier(int scanner, int printer, int power)
    : PoweredDevice{ power }
    , Scanner{ scanner, power }
    , Printer{ printer, power }
  { 
  }

};

class HPPrinter : public Printer {
public:
  HPPrinter(int printer, int power)
    : PoweredDevice{ power }
    , Printer{ printer, power }
  {
  }
};

int32_t main() {
  Copier copier{ 1, 2, 3 };

  HPPrinter hpPrinter{ 1, 2 };

  return 0;
}
