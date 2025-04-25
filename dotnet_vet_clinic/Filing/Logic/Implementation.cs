using Filing.Models;

namespace Filing.Implementation;

public class Implementation : IImplementation
{
    public bool AddClient(Client client)
    {
        Console.WriteLine(client.Name + " " + client.Address + " " + client.PhoneNumber + " " + client.GetId());
        return true;
    }
}