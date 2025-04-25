using Filing.Logic;
using Filing.Models;
using Microsoft.AspNetCore.Mvc;

namespace Filing.Controllers;

[Route("api/pet")]
[ApiController]
public class PetController(IImplementation implementation) : ControllerBase
{
    // POST api/pet
    [HttpGet("new_chip")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    public IActionResult GetNewChip()
    {
        return Ok(Guid.NewGuid().ToString());
    }

    // POST api/pet
    [HttpPost]
    [ProducesResponseType(StatusCodes.Status201Created)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Post([FromBody] CreatePetRequest request)
    {
        var success = implementation.AddPet(request.ClientPhoneNumber, request.PetInfo);

        if (success)
        {
            var location = Url.Action(nameof(Post), new { id = request.PetInfo.ChipNumber }) ??
                           $"/{request.PetInfo.ChipNumber}";
            return Created(location, request.PetInfo);
        }

        // TODO add better return codes once we can differentiate in the implementation return
        return Problem();
    }

    // GET api/pet/{chipId}
    [HttpGet("{chipNumber}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public IActionResult Get(string chipNumber)
    {
        var pet = implementation.GetPetByChipNumber(chipNumber);

        if (pet is not null)
        {
            return Ok(pet);
        }

        return NotFound();
    }
}