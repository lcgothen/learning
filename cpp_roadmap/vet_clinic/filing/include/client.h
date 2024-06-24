#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include <person.h>
#include <pet.h>

class Client : public Person {
public:
    Client(std::string name, std::string address, std::string phone_number, IDManager& id_manager) : Person(name, address, phone_number, id_manager) {}

    // get info
    std::vector<Pet> get_pets();

    // change info
    void add_pet(Pet pet);
    void remove_pet(int id);
    void update_pet_info(int id, std::string new_name, double weight, Sex sex);

private:
std::vector<Pet> pets_; 
};

#endif // CLIENT_H