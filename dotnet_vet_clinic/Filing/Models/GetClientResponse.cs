namespace Filing.Models;

public class GetClientResponse(Client client, List<Pet> pets)
{
    public Client Client { get; set; } = client;
    public List<Pet> Pets { get; set; } = pets;
}