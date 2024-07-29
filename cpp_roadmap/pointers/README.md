# Pointers

Pointers are well known as being complex in c++, with a big concern being memory leaks. Memory leaks occur when a program allocates memory, but never releases it again. Since memory is not an unending resource, this can lead to running out of available memory.

Raw pointers require careful memory management, while smart pointers are safer in that regard. Specifically, smart pointers destroy themselves (freeing the memory allocation) when they go out of scope.

## Smart pointers

There are 3 types of smart pointers: unique, shared and weak. 

Unique pointers have exclusive ownership of the object they point to, so the object is automatically deleted when the pointer goes out of scope.

With shared pointers, several can point to the same object. Only when all shared pointers to an object go out of scope, is the object deleted.

Weak pointers are similar to shared pointers, but the object can be deleted before these pointers go out of scope, if all shared pointers to that object are out of scope. The memory blovk is only deallocated after all weak pointers have gone out of scope, so as to detetc safely if an object has been deleted.