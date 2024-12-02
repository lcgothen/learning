#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include <clinic_database.h>

void wait_and_clear() {
    std::cout << "Press enter to continue" << std::endl;
    std::string input;
    std::getline( std::cin, input );
    system("clear");
}

int main() {
    // initialize stuff -> in reality it would be an actual database
    ClinicDatabase db;
    bool stop = false;
    system("clear");
    
    while(!stop) {
        std::cout << "What can we help with?" << std::endl;
        std::cout << "1. Register new pet" << std::endl;
        std::cout << "2. Register new client" << std::endl;
        std::cout << "3. Go to management menu" << std::endl;
        std::cout << "100. Quit" << std::endl;

        std::string input;
        std::getline( std::cin, input );

        int operation;
        try {
            operation = std::stoi(input);
        } catch (std::invalid_argument const&) {
            system("clear");
            std::cout << "Please choose one of the available options!" << std::endl;
            continue;
        }

        switch(operation){
            case 1: {
                db.add_pet();
                wait_and_clear();
            } break;
            case 2: {
                db.add_client();
                wait_and_clear();
            } break;
            case 3: {
                stop = true;
                // same same as the other stuff, I'll move on from this example for now
            } break;
            case 100: {
                stop = true;
            } break;
            default: {
                system("clear");
                std::cout << "Please choose one of the available options!" << std::endl;
            } break;
        }
    }

  return 0;
}