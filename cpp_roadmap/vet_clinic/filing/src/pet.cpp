#include <pet.h>

// super simple stuff, but could be more complex in the future

Pet::Pet(std::string name, PetType pet_type, Sex sex, double weight, IDManager& id_manager) : name_(name), pet_type_(pet_type), sex_(sex), weight_(weight) {
    id_ = id_manager.get_new_id();
}

std::string Pet::get_pet_type_string() {
    switch(pet_type_){
        case PetType::CAT: {
            return "cat";
        } 
        case PetType::DOG: {
            return "dog";
        } 
        case PetType::RABBIT: {
            return "rabbit";
        } 
        case PetType::SNAKE: {
            return "snake";
        } 
        case PetType::LIZARD: {
            return "lizard";
        } 
        default: {
            return "Unknown";
        }
    }
}

std::string Pet::get_sex_string() {
    switch(sex_){
        case Sex::MALE: {
            return "male";
        } 
        case Sex::FEMALE: {
            return "female";
        } 
        default: {
            return "Unknown";
        }
    }
}

void Pet::change_name(std::string new_name) {
    name_ = new_name;
}

void Pet::update_pet_weight(double weight) {
    weight_ = weight;
}