#include <iostream>
#include <memory>
#include <stdexcept>
#include <stdint.h>
#include <string.h>
#include <typeinfo>

class empty_class {
public:
  virtual ~empty_class();
};

int main() {
  try {
    throw "This is my custom exception!";
  } catch (const char *e) {
    std::cout << "Error: " << e << std::endl;
  }

  // There's different types of exceptions
  // This is a bad_typeid exception
  // So we can specify which kind of exception we want to catch and what to do
  // with it
  try {
    empty_class *null_val = NULL;
    std::cout << "Trying to get typeid of null_val: "
              << typeid(*null_val).name() << std::endl;
  } catch (std::bad_typeid &) {
    std::cout << "Bad type exception" << std::endl;
  } catch (const char *e) {
    std::cout << "Error: " << e << std::endl;
  }

  return 0;
}