using Filing.Models;
using Microsoft.AspNetCore.Mvc;

namespace Filing.Controllers;

[Route("api/[controller]")]
[ApiController]
public class PersonController : ControllerBase
{
    // POST api/<PersonController>
    [HttpPost]
    public void Post([FromBody] Person request)
    {
    }
}