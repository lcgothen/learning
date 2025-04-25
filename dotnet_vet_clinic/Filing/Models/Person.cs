namespace Filing.Models;

public class Person(string name, string address, string phoneNumber)
{
    public string Name { get; set; } = name;
    public string Address { get; set; } = address;
    public string PhoneNumber { get; set; } = phoneNumber; // phone number is the unique identifier
}