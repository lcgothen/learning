using Filing.Models;

namespace Filing.Logic;

public interface IImplementation
{
    ReturnCodes AddClient(Client client);
    Client? GetClientByPhoneNumber(string phoneNumber);
    ReturnCodes DeleteClient(string phoneNumber);
    ReturnCodes AddPet(string clientPhoneNumber, Pet pet);
    Pet? GetPetByChipNumber(string chipNumber);
    ReturnCodes DeletePet(string chipNumber);
    ReturnCodes AddEmployee(Employee employee);
    Employee? GetEmployeeByPhoneNumber(string phoneNumber);
    ReturnCodes DeleteEmployee(string phoneNumber);
}