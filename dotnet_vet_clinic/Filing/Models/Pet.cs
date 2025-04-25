namespace Filing.Models;

public class Pet(string chipNumber, string name, Pet.Type petType, double weight)
{
    // TODO get this type to be inserted as string
    public enum Type
    {
        Unknown = 0,
        Cat = 1,
        Dog = 2,
        Rabbit = 3,
        Snake = 4,
        Lizard = 5
    }


    public string ChipNumber { get; } = chipNumber;
    public string Name { get; set; } = name;
    public Type PetType { get; set; } = petType;
    public double Weight { get; set; } = weight;
}