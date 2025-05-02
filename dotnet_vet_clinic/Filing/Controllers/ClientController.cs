using Filing.Logic;
using Filing.Models;
using Microsoft.AspNetCore.Mvc;

namespace Filing.Controllers;

[Route("api/client")]
[ApiController]
public class ClientController(IImplementation implementation) : ControllerBase
{
    // POST api/client
    [HttpPost]
    [ProducesResponseType(StatusCodes.Status201Created)]
    [ProducesResponseType(StatusCodes.Status409Conflict)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Post([FromBody] Client request)
    {
        var ret = implementation.AddClient(request);

        switch (ret)
        {
            case ReturnCodes.Conflict:
                return Conflict("A customer with this phone number is already registered.");
            case ReturnCodes.Success:
                var location = Url.Action(nameof(Post), new { id = request.PhoneNumber }) ??
                               $"/{request.PhoneNumber}";
                return Created(location, request);
            case ReturnCodes.NotFound:
            case ReturnCodes.UnknownError:
            default:
                return Problem();
        }
    }

    // GET api/client/{phoneNumber}
    [HttpGet("{phoneNumber}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Get(string phoneNumber)
    {
        var client = implementation.GetClientByPhoneNumber(phoneNumber);

        if (client is null)
        {
            return NotFound("Customer with this phone number does not exist.");
        }

        var allPetsChipNumbers = client.GetAllPets();
        var pets = new List<Pet>();

        foreach (var petChipNumber in allPetsChipNumbers)
        {
            var pet = implementation.GetPetByChipNumber(petChipNumber);

            if (pet is null)
            {
                // shouldn't happen as we got the chip number internally
                return Problem();
            }

            pets.Add(pet);
        }

        return Ok(new GetClientResponse(client, pets));
    }

    // DELETE api/client/{phoneNumber}
    [HttpDelete("{phoneNumber}")]
    [ProducesResponseType(StatusCodes.Status204NoContent)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Delete(string phoneNumber)
    {
        var ret = implementation.DeleteClient(phoneNumber);

        switch (ret)
        {
            case ReturnCodes.NotFound:
                return NotFound("Customer with this phone number does not exist.");
            case ReturnCodes.Success:
                return NoContent();
            case ReturnCodes.Conflict:
            case ReturnCodes.UnknownError:
            default:
                return Problem();
        }
    }
}