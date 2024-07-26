#ifndef CLINIC_DATABASE_H
#define CLINIC_DATABASE_H

#include <vector>

#include <pet.h>
#include <client.h>
#include <employee.h>
#include <id_manager.h>

class ClinicDatabase {
public:

    void add_pet();

    void add_client();

private:
    std::vector<Client> clients_;
    std::vector<Employee> employees_;
    IDManager client_id_manager_;
    IDManager employee_id_manager_;
    IDManager pet_id_manager_;
};

#endif // CLINIC_DATABASE_H