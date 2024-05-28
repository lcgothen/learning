#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include <person.h>

class Client : public Person {
public:
    // get info
    std::vector<Pet> get_pets();

    // change info
    void add_pet(Pet pet);
    void remove_pet(int id);
    void update_pet_info(Pet new_pet_info);

private:
std::vector<Pet> pets_; 
};

#endif // CLIENT_H