#include <iostream>

#include <clinic_database.h>

void ClinicDatabase::add_pet() {
    // Client info
    std::cout << "Input your ID:" << std::endl;
    std::string client_id = "ID";
    std::getline( std::cin, client_id );

    int cliend_id_int;
    try {
        cliend_id_int = std::stoi(client_id);
    } catch (std::invalid_argument const&) {
        std::cout << "Invalid ID!" << std::endl;
    }

    // lookup client
    int index = -1;
    for(int i=0; i< static_cast<int>(clients_.size()); i++){
        if (clients_[i].get_id() == cliend_id_int) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        std::cout << "Couldn't find requested client! You should register yourself before your pet." << std::endl;
        return;
    }

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

    clients_[index].add_pet(Pet(name, pet_type, sex, weight, pet_id_manager_));
    system("clear");
    std::cout << name << " is registered to " << clients_[index].get_name() << "!" << std::endl;
}

void ClinicDatabase::add_client() {
    // name
    std::cout << "Input your name:" << std::endl;
    std::string name = "name";
    std::getline( std::cin, name );

    // address
    std::cout << "Input your address:" << std::endl;
    std::string address = "address";
    std::getline( std::cin, address );

    // phone number
    std::cout << "Input your phone number:" << std::endl;
    std::string phone_number = "phone_number";
    std::getline( std::cin, phone_number );

    clients_.emplace_back(Client(name, address, phone_number, client_id_manager_));
    system("clear");

    std::cout << "You have been registered with ID " << clients_.back().get_id() << std::endl;
}