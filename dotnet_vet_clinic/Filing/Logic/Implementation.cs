using Filing.Models;

namespace Filing.Logic;

public class Implementation : IImplementation
{
    private readonly List<Client> _clients = new();

    private readonly List<Pet> _pets = new();

    public bool AddClient(Client client)
    {
        var existingClient = _clients.Find(c => c.PhoneNumber == client.PhoneNumber);
        if (existingClient is not null)
        {
            return false;
        }

        _clients.Add(client);
        return true;
    }

    public Client? GetClientByPhoneNumber(string phoneNumber)
    {
        return _clients.Find(c => c.PhoneNumber == phoneNumber);
    }

    public bool AddPet(string clientPhoneNumber, Pet pet)
    {
        var client = _clients.Find(c => c.PhoneNumber == clientPhoneNumber);
        if (client is null)
        {
            return false;
        }

        var existingPet = _pets.Find(p => p.ChipNumber == pet.ChipNumber);
        if (existingPet is not null)
        {
            return false;
        }

        client.AddPet(pet.ChipNumber);
        _pets.Add(pet);

        return true;
    }

    public Pet? GetPetByChipNumber(string chipNumber)
    {
        return _pets.Find(p => p.ChipNumber == chipNumber);
    }
}