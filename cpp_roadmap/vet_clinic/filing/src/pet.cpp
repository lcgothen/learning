#include "../include/pet.h"

// super simple stuff, but could be more complex in the future

Pet(std::string name, PetType pet_type, Sex sex, time_t birth, double weight, IDManager& id_manager) : name_(name), pet_type_(pet_type), sex_(sex), birth_(birth), weight_(weight) {
    id_ = id_manager.get_next_id();
}

void Pet::change_name(std::string new_name) {
    name_ = new_name;
}

void Pet::update_pet_weight(double weight) {
    weight_ = weight;
}