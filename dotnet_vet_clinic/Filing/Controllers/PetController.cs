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
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status409Conflict)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Post([FromBody] CreatePetRequest request)
    {
        var ret = implementation.AddPet(request.ClientPhoneNumber, request.PetInfo);

        switch (ret)
        {
            case ReturnCodes.Conflict:
                return Conflict("A pet with this chip number is already registered.");
            case ReturnCodes.NotFound:
                return NotFound(
                    "Customer with this phone number does not exist. Make sure to register as a customer before registering pets!");
            case ReturnCodes.Success:
                var location = Url.Action(nameof(Post), new { id = request.PetInfo.ChipNumber }) ??
                               $"/{request.PetInfo.ChipNumber}";
                return Created(location, request.PetInfo);
            case ReturnCodes.UnknownError:
            default:
                return Problem();
        }
    }

    // GET api/pet/{chipId}
    [HttpGet("{chipNumber}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public IActionResult Get(string chipNumber)
    {
        var pet = implementation.GetPetByChipNumber(chipNumber);

        if (pet is null)
        {
            return NotFound();
        }

        return Ok(pet);
    }

    // DELETE api/pet/{chipId}
    [HttpDelete("{chipNumber}")]
    [ProducesResponseType(StatusCodes.Status204NoContent)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Delete(string chipNumber)
    {
        var ret = implementation.DeletePet(chipNumber);

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