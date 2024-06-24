#include <person.h>

// super simple stuff, but could be more complex in the future

Person::Person(std::string name, std::string address, std::string phone_number, IDManager& id_manager) : name_(name), address_(address), phone_number_(phone_number) {
    id_ = id_manager.get_new_id();
}

int Person::get_id() { 
    return id_;
}

std::string Person::get_name() { 
    return name_;
}

std::string Person::get_address() { 
    return address_;
}

std::string Person::get_phone_number() { 
    return phone_number_;
}

void Person::change_address(std::string new_address) {
    address_ = new_address;
}

void Person::change_phone_number(std::string new_phone_number) { 
    phone_number_ = new_phone_number;
}