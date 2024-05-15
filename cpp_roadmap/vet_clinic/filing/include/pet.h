#ifndef PET_H
#define PET_H

#include <string>

#include "id_manager.h"

enum class PetType {
    UNKNOWN = 0,
    CAT = 1,
    DOG = 2,
    RABBIT = 3,
    SNAKE = 4,
    LIZARD = 5,
};

enum class Sex {
    UNKNOWN = 0,
    FEMALE = 1,
    MALE= 2,
};

class Pet {
public:
    // ************* figure out constructor *************
    Pet(std::string name, PetType pet_type, Sex sex, time_t birth, double weight, IDManager& id_manager);

    // get info
    std::string get_name() {return name_;};
    int get_id() {return id_;};
    PetType get_pet_type() {return pet_type_;};
    Sex get_sex() {return sex_;};
    time_t get_birth() {return birth_;};
    double get_weight() {return weight_;};

    // change info
    void change_name(std::string new_name);
    void update_pet_weight(double weight);

private:
    std::string name_;
    int id_; // for simplicity's sake, we'll assume the clinic won't have lots of patients :)
    PetType pet_type_;
    Sex sex_;
    time_t birth_;
    double weight_;
};

#endif // PET_H