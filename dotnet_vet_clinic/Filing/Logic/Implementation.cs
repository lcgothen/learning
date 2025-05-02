using Filing.Models;

namespace Filing.Logic;

public class Implementation : IImplementation
{
    private readonly List<Client> _clients = new();
    private readonly List<Employee> _employees = new();
    private readonly List<Pet> _pets = new();

    public ReturnCodes AddClient(Client client)
    {
        var existingClient = _clients.Find(c => c.PhoneNumber == client.PhoneNumber);
        if (existingClient is not null)
        {
            return ReturnCodes.Conflict;
        }

        _clients.Add(client);
        return ReturnCodes.Success;
    }

    public Client? GetClientByPhoneNumber(string phoneNumber)
    {
        return _clients.Find(c => c.PhoneNumber == phoneNumber);
    }

    public ReturnCodes DeleteClient(string phoneNumber)
    {
        var client = _clients.Find(c => c.PhoneNumber == phoneNumber);
        if (client is null)
        {
            return ReturnCodes.NotFound;
        }

        // De-register all of this client's pets
        foreach (var petChipNumber in client.GetAllPets())
        {
            _pets.RemoveAll(p => p.ChipNumber == petChipNumber);
        }

        _clients.RemoveAll(c => c.PhoneNumber == phoneNumber);
        return ReturnCodes.Success;
    }

    public ReturnCodes AddPet(string clientPhoneNumber, Pet pet)
    {
        var client = _clients.Find(c => c.PhoneNumber == clientPhoneNumber);
        if (client is null)
        {
            return ReturnCodes.NotFound;
        }

        var existingPet = _pets.Find(p => p.ChipNumber == pet.ChipNumber);
        if (existingPet is not null)
        {
            return ReturnCodes.Conflict;
        }

        client.AddPet(pet.ChipNumber);
        _pets.Add(pet);

        return ReturnCodes.Success;
    }

    public Pet? GetPetByChipNumber(string chipNumber)
    {
        return _pets.Find(p => p.ChipNumber == chipNumber);
    }

    public ReturnCodes DeletePet(string chipNumber)
    {
        var nDeleted = _pets.RemoveAll(p => p.ChipNumber == chipNumber);

        return nDeleted == 0 ? ReturnCodes.NotFound : ReturnCodes.Success;
    }

    public ReturnCodes AddEmployee(Employee employee)
    {
        var existingEmployee = _clients.Find(e => e.PhoneNumber == employee.PhoneNumber);
        if (existingEmployee is not null)
        {
            return ReturnCodes.Conflict;
        }

        _employees.Add(employee);
        return ReturnCodes.Success;
    }

    public Employee? GetEmployeeByPhoneNumber(string phoneNumber)
    {
        return _employees.Find(e => e.PhoneNumber == phoneNumber);
    }

    public ReturnCodes DeleteEmployee(string phoneNumber)
    {
        var nDeleted = _clients.RemoveAll(c => c.PhoneNumber == phoneNumber);

        return nDeleted == 0 ? ReturnCodes.NotFound : ReturnCodes.Success;
    }
}