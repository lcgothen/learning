#include <cstdlib>
#include <iostream>
#include <stdint.h>

void simple_function(int val) {
  std::cout << "Simple function called with value: " << val << std::endl;
}

void simple_function(int &val1, int &val2) {
  // this function gets 2 values as references and swaps them around
  std::cout << "Simple function called with values: " << val1 << " and " << val2
            << std::endl;

  std::cout << "Swapping the values" << std::endl;

  auto aux = val1;
  val1 = val2;
  val2 = aux;
}

int main() {
  const int const_val = 0;
  int val1 = 1;
  int val2 = 2;

  // we have 2 functions with the same name, but different arguments, so we're
  // using argument dependent lookup
  simple_function(const_val);

  std::cout << "Values before swap: val1 = " << val1 << "; val2 = " << val2
            << std::endl;
  simple_function(val1, val2);
  std::cout << "Values after swap: val1 = " << val1 << "; val2 = " << val2
            << std::endl;

  // let's try to do it with the const value
  // we need to cast it to be able to pass it to the function
  // it will still remain unchanged, as we are not actually changing the type of
  // the const_val variable but val2 will still get changed
  std::cout << "Values before swap: const_val = " << const_val
            << "; val2 = " << val2 << std::endl;
  simple_function(*(const_cast<int *>(&const_val)), val2);
  std::cout << "Values after swap: const_val = " << const_val
            << "; val2 = " << val2 << std::endl;
}