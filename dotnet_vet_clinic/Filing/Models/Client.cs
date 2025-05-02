namespace Filing.Models;

public class Client(string name, string address, string phoneNumber) : Person(name, address, phoneNumber)
{
    private readonly List<string> _pets = new();

    public void AddPet(string petId)
    {
        _pets.Add(petId);
    }

    public void RemovePet(string petId)
    {
        _pets.Remove(petId);
    }

    public List<string> GetAllPets()
    {
        return _pets;
    }
}