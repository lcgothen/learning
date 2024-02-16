#ifndef PET_H
#define PET_H

#include <string>

class Pet {
public:
    // ************* figure out constructor *************

    // get info
    std::string get_name();
    int get_id();
    PetType get_pet_type();
    Sex get_sex();
    time_t get_birth();
    double get_weight();

    // change info
    void change_name();

private:
    std::string name_;
    int id_; // for simplicity's sake, we'll assume the clinic won't have lots of patients :)
    PetType pet_type_;
    Sex sex_;
    time_t birth;
    double weight;
};

enum PetType {
    UNKNOWN = 0,
    CAT = 1,
    DOG = 2,
    RABBIT = 3,
    SNAKE = 4,
    LIZARD = 5,
};

enum Sex {
    UNKNOWN = 0,
    FEMALE = 1,
    MALE= 2,
};

#endif // PET_H