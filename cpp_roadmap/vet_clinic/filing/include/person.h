#ifndef PERSON_H
#define PERSON_H


class Person {
public:
    // get info
    int get_id();
    std::string get_address();
    std::string get_phone_number();

    // change info
    void change_address(std::string new_address);
    void change_phone_number(std::string new_phone_number);

private:
int id_; // for simplicity's sake, we'll assume the clinic won't have lots of people :)
std::string address_;
std::string phone_number_;
};

#endif // PERSON_H