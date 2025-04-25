namespace Filing.Models;

public class CreatePetRequest(string clientPhoneNumber, Pet petInfo)
{
    public string ClientPhoneNumber { get; set; } = clientPhoneNumber;
    public Pet PetInfo { get; set; } = petInfo;
}