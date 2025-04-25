using Filing.Implementation;
using Filing.Models;
using Microsoft.AspNetCore.Mvc;

namespace Filing.Controllers;

[Route("api/client")]
[ApiController]
public class ClientController(IImplementation implementation) : ControllerBase
{
    // POST api/client
    [HttpPost]
    public void Post([FromBody] Client request)
    {
        implementation.AddClient(request);
    }
}