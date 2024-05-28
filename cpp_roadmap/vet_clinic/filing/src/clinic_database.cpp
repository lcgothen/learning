#include <iostream>

#include <clinic_database.h>

void ClinicDatabase::add_pet(){
    // name
    std::cout << "Input your pet's name:" << std::endl;
    std::string name = "name";
    std::getline( std::cin, name );

    // pet type
    PetType pet_type;
    std::cout << "Choose which animal your pet is:" << std::endl;
    std::cout << "1. Cat" << std::endl;
    std::cout << "2. Dog" << std::endl;
    std::cout << "3. Rabbit" << std::endl;
    std::cout << "4. Snake" << std::endl;
    std::cout << "5. Lizard" << std::endl;

    std::string input;
    std::getline( std::cin, input );

    try {
        pet_type = static_cast<PetType>(std::stoi(input));
    } catch (std::invalid_argument const&) {
        std::cout << "Please choose one of the available options!" << std::endl;
    }

    // sex
    Sex sex;
    std::cout << "Choose your pet's sex':" << std::endl;
    std::cout << "1. Male" << std::endl;
    std::cout << "2. Female" << std::endl;

    std::getline( std::cin, input );

    try {
        sex = static_cast<Sex>(std::stoi(input));
    } catch (std::invalid_argument const&) {
        std::cout << "Please choose one of the available options!" << std::endl;
    }

    // weight
    double weight;
    std::cout << "Input your pet's weight:" << std::endl;
    std::getline( std::cin, input );

    try {
        weight = std::stod(input);
    } catch (std::invalid_argument const&) {
        std::cout << "Please input a valid value!" << std::endl;
    }

    pets_.emplace_back(Pet(name, pet_type, sex, weight, pet_id_manager_));
    system("clear");
    std::cout << pets_.back().get_name() << " is registered!" << std::endl;

    std::cout << "Name: " << pets_.back().get_name() << std::endl;
    std::cout << "Animal Type: " << pets_.back().get_pet_type_string() << std::endl;
    std::cout << "Sex: " << pets_.back().get_sex_string() << std::endl;
    std::cout << "Weight: " << pets_.back().get_weight() << std::endl;

    std::cout << "Press enter to continue" << std::endl;
    std::getline( std::cin, input );
}