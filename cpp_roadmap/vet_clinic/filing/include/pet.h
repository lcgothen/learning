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
    MALE= 1,
    FEMALE = 2,
};

class Pet {
public:
    // ************* figure out constructor *************
    Pet(std::string name, PetType pet_type, Sex sex, double weight, IDManager& id_manager);

    // get info
    std::string get_name() {return name_;};
    int get_id() {return id_;};
    PetType get_pet_type() {return pet_type_;};
    std::string get_pet_type_string();
    Sex get_sex() {return sex_;};
    std::string get_sex_string();
    double get_weight() {return weight_;};

    // change info
    void change_name(std::string new_name);
    void update_pet_weight(double weight);
    void update_pet_sex(Sex sex);

private:
    std::string name_;
    int id_; // for simplicity's sake, we'll assume the clinic won't have lots of patients :)
    PetType pet_type_;
    Sex sex_;
    double weight_;
};

#endif // PET_H