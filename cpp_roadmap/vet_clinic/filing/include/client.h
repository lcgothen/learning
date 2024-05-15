#ifndef CLIENT_H
#define CLIENT_H

#include <Pet.h>

class Client : public Person {
public:
    // get info
    std::list<Pet> get_pets();

    // change info
    void add_pet(std::list<Pet> pet);
    void remove_pet(int id);
    void update_pet_info(std::list<Pet> new_pet_info);

private:
std::list<Pet> pets_; 
};

#endif // CLIENT_H