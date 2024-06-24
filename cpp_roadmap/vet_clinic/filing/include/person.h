#ifndef PERSON_H
#define PERSON_H

#include <string>

#include "id_manager.h"


class Person {
public:
    Person(std::string name, std::string address, std::string phone_number, IDManager& id_manager);

    // get info
    int get_id();
    std::string get_name();
    std::string get_address();
    std::string get_phone_number();

    // change info
    void change_address(std::string new_address);
    void change_phone_number(std::string new_phone_number);

private:
int id_; // for simplicity's sake, we'll assume the clinic won't have lots of people :)
std::string name_;
std::string address_;
std::string phone_number_;
};

#endif // PERSON_H