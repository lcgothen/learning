#include <iostream>
#include <memory>
#include <stdint.h>

template <typename T> T add(T t1, T t2) { return t1 + t2; }

// partial specialization
template <typename T> T add(T t1, char t2) {
  std::cout << "(partial specialization) ";
  return t1 + t2;
}

int main() {
  int int1 = 1;
  int int2 = 2;
  std::cout << int1 << " + " << int2 << " = " << add(int1, int2) << std::endl;

  float float1 = 1.1;
  float float2 = 2.34;
  std::cout << float1 << " + " << float2 << " = " << add(float1, float2)
            << std::endl;

  // it even works with strings, as the + symbol concatenates
  std::string string1 = "string1 ";
  std::string string2 = "string2 ";
  std::cout << string1 << " + " << string2 << " = " << add(string1, string2)
            << std::endl;

  // now we can try calling the partial specialization
  char char1 = 'a';
  std::cout << int1 << " + " << char1 << " = " << add(int1, char1) << std::endl;
}