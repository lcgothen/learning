# Type Casting

* *C-style*: this is inherited from C, and is not the recommended way of casting. 
* *static_cast*: safer alternative to C-style casting, as it gives an error if there is no valid conversion at compile-time. It is used to convert between different data types.
* *dynamic_cast*: used for polymorphism, so it allows conversion of pointers and of a class to it's dereived class. It returns a null pointer if there is no valid conversion at runtime.
* *const_cast*: used to change the constness of a variable. Not recommended, as it can give undefined behavior when misused. 
* *reinterpret_cast*: used to change the type of a pointer or converting between integer types and pointer types. Not recommended, as it can give undefined behavior when misused. 