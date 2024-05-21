#include <iostream>
#include <stdlib.h>
#include <stdexcept>

int main() {
    std::cout << "Welcome to the vet clinic! What can we help with?" << std::endl;

    bool stop = false;
    system("clear");
    
    while(!stop) {
        std::cout << "What can we help with?" << std::endl;
        std::cout << "1. Register new pet" << std::endl;
        std::cout << "2. Register new client" << std::endl;
        std::cout << "3. Quit" << std::endl;

        std::string input;
        std::getline( std::cin, input );

        int operation;
        try {
            operation = std::stoi(input);
        } catch (std::invalid_argument) {
            system("clear");
            std::cout << "Please choose one of the available options!" << std::endl;
            continue;
        }

        switch(operation){
            case 3: {
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