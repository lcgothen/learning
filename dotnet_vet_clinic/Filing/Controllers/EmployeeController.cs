using Filing.Logic;
using Filing.Models;
using Microsoft.AspNetCore.Mvc;

namespace Filing.Controllers;

[Route("api/employee")]
[ApiController]
public class EmployeeController(IImplementation implementation) : ControllerBase
{
    // POST api/employee
    [HttpPost]
    [ProducesResponseType(StatusCodes.Status201Created)]
    [ProducesResponseType(StatusCodes.Status409Conflict)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Post([FromBody] Employee employee)
    {
        var ret = implementation.AddEmployee(employee);

        switch (ret)
        {
            case ReturnCodes.Conflict:
                return Conflict("An employee with this phone number is already registered.");
            case ReturnCodes.Success:
                var location = Url.Action(nameof(Post), new { id = employee.PhoneNumber }) ??
                               $"/{employee.PhoneNumber}";
                return Created(location, employee);
            case ReturnCodes.NotFound:
            case ReturnCodes.UnknownError:
            default:
                return Problem();
        }
    }

    // GET api/employee/{phoneNumber}
    [HttpGet("{phoneNumber}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Get(string phoneNumber)
    {
        var employee = implementation.GetEmployeeByPhoneNumber(phoneNumber);

        if (employee is null)
        {
            return NotFound("Employee with this phone number does not exist.");
        }

        return Ok(employee);
    }

    // DELETE api/employee/{phoneNumber}
    [HttpDelete("{phoneNumber}")]
    [ProducesResponseType(StatusCodes.Status204NoContent)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status500InternalServerError)]
    public IActionResult Delete(string phoneNumber)
    {
        var ret = implementation.DeleteEmployee(phoneNumber);

        switch (ret)
        {
            case ReturnCodes.NotFound:
                return NotFound("Employee with this phone number does not exist.");
            case ReturnCodes.Success:
                return NoContent();
            case ReturnCodes.Conflict:
            case ReturnCodes.UnknownError:
            default:
                return Problem();
        }
    }
}