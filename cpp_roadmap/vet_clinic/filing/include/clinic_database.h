#ifndef CLINIC_DATABASE_H
#define CLINIC_DATABASE_H

#include <list>

#include <pet.h>
#include <client.h>
#include <employee.h>
#include <id_manager.h>

class ClinicDatabase {
public:

    void add_pet();

private:
    std::list<Client> clients_;
    std::list<Employee> employees_;
    std::list<Pet> pets_; // this will disappear, as it should be associated with each client
    IDManager client_id_manager_;
    IDManager employee_id_manager_;
    IDManager pet_id_manager_;
};

#endif // CLINIC_DATABASE_H