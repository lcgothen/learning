#include <iostream>
#include <memory>
#include <stdint.h>

int main() {
  // We will demonstrate misusing weak pointers :)

  std::cout << "This will end in a segmentation fault :)" << std::endl;

  std::shared_ptr<std::string> my_shared_ptr =
      std::make_unique<std::string>("MyPointer");
  std::weak_ptr<std::string> my_weak_ptr = my_shared_ptr;
  std::cout << "my_shared_ptr: " << *my_shared_ptr << std::endl;
  std::cout << "my_weak_ptr: " << *(my_weak_ptr.lock()) << std::endl;

  my_shared_ptr.reset();
  std::cout << "I reset the shared pointer, so I can no longer access what the "
               "weak pointer is pointing at"
            << std::endl;

  std::cout << "my_weak_ptr: " << *(my_weak_ptr.lock()) << std::endl;

  return 0;
}