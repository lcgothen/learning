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
    public IActionResult Post([FromBody] Client request)
    {
        var success = implementation.AddClient(request);

        if (success)
        {
            var location = Url.Action(nameof(Post), new { id = request.PhoneNumber }) ??
                           $"/{request.PhoneNumber}";
            return Created(location, request);
        }

        return Conflict();
    }

    // GET api/client/{phoneNumber}
    [HttpGet("{phoneNumber}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public IActionResult Get(string phoneNumber)
    {
        var client = implementation.GetClientByPhoneNumber(phoneNumber);

        if (client is null)
        {
            return NotFound();
        }

        var pets = new List<Pet>();

        foreach (var petChipNumber in client.GetAllPets())
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
}