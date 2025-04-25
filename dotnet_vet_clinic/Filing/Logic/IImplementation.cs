using Filing.Models;

namespace Filing.Logic;

public interface IImplementation
{
    bool AddClient(Client client);
    Client? GetClientByPhoneNumber(string phoneNumber);
    bool AddPet(string clientPhoneNumber, Pet pet);
    Pet? GetPetByChipNumber(string chipNumber);
}