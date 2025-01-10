namespace Filing.Models;

public class Pet(string name, Pet.Type petType, double weight)
{
    public enum Type
    {
        UNKNOWN = 0,
        CAT = 1,
        DOG = 2,
        RABBIT = 3,
        SNAKE = 4,
        LIZARD = 5
    }

    private readonly Guid _id = Guid.NewGuid();

    public string Name { get; set; } = name;
    public Type PetType { get; set; } = petType;
    public double Weight { get; set; } = weight;

    public string GetId()
    {
        return _id.ToString();
    }
}