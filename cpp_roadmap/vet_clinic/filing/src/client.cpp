#include <client.h>
#include <iostream>
#include <vector>


// super simple stuff, but could be more complex in the future

 std::vector<Pet> Client::get_pets() {
    return pets_;
 }

void Client::add_pet(Pet pet) {
    pets_.emplace_back(pet);
};

void Client::remove_pet(int id) {
    int index = -1;

    for(int i=0; i< static_cast<int>(pets_.size()); i++){
        if (pets_[i].get_id() == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Couldn't find requested pet!" << std::endl;
        return;
    }

    pets_.erase(pets_.begin()+index);
}

void Client::update_pet_info(int id, std::string new_name, double weight, Sex sex) {
    int index = -1;

    for(int i=0; i< static_cast<int>(pets_.size()); i++){
        if (pets_[i].get_id() == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Couldn't find requested pet!" << std::endl;
        return;
    }

    pets_[index].change_name(new_name);
    pets_[index].update_pet_weight(weight);
    pets_[index].update_pet_sex(sex);
}