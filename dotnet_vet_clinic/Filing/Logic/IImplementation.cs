using Filing.Models;

namespace Filing.Logic;

public interface IImplementation
{
    ReturnCodes AddClient(Client client);
    Client? GetClientByPhoneNumber(string phoneNumber);
    ReturnCodes AddPet(string clientPhoneNumber, Pet pet);
    Pet? GetPetByChipNumber(string chipNumber);
}