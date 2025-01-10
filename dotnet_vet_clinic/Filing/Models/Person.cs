namespace Filing.Models;

public class Person(string name, string address, string phoneNumber)
{
    private readonly Guid _id = Guid.NewGuid();

    public string Name { get; set; } = name;
    public string Address { get; set; } = address;
    public string PhoneNumber { get; set; } = phoneNumber;

    public string GetId()
    {
        return _id.ToString();
    }
}