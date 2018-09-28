using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WSConvertisseur.Models;

namespace WSConvertisseur.Controllers
{
    [Produces("application/json")]
    [Route("api/Devise")]
    public class DeviseController : Controller
    {
        // GET: api/Devise
        [HttpGet]
        public IEnumerable<Devise> GetAll()
        {
            return devises.AsEnumerable();
        }

        // GET: api/Devise/5
        [HttpGet("{id}", Name = "GetDevise")]
        public IActionResult GetById(int id)
        {
            Devise devise = devises.FirstOrDefault((d) => d.Id == id);
            if(devise == null)
            {
                return NotFound();
            }
            return Ok(devise);
        }

        // POST: api/Devise
        [HttpPost]
        public IActionResult Post([FromBody]Devise devise)
        {
            if(!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }
            devises.Add(devise);
            return CreatedAtRoute("GetDevise", new { id = devise.Id }, devise);
        }

        // PUT: api/Devise/5
        [HttpPut("{id}")]
        public IActionResult Put(int id, [FromBody] Devise devise)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }
            if(id != devise.Id)
            {
                return BadRequest();
            }
            int index = devises.FindIndex((d) => d.Id == id);
            if(index < 0)
            {
                return NotFound();
            }
            devises[index] = devise;
            return NoContent();
        }

        // DELETE: api/ApiWithActions/5
        [HttpDelete("{id}", Name = "DeleteDevise")]
        public IActionResult DeleteById(int id)
        {
            Devise devise = devises.FirstOrDefault((d) => d.Id == id);
            if (devise == null)
            {
                return NotFound();
            }
            devises.Remove(devise);
            return Ok(devise);
        }

        public DeviseController()
        {
            devises = new List<Devise>();
            Devise dollar = new Devise
            {
                Id = 1,
                NomDevise = "Dollar",
                Taux = 1.08
            };
            Devise francSuisse = new Devise
            {
                Id = 2,
                NomDevise = "Franc Suisse",
                Taux = 1.07
            };
            Devise yen = new Devise
            {
                Id = 3,
                NomDevise = "Yen",
                Taux = 120
            };

            devises.Add(dollar);
            devises.Add(francSuisse);
            devises.Add(yen);
        }

        private List<Devise> devises;
    }
}
