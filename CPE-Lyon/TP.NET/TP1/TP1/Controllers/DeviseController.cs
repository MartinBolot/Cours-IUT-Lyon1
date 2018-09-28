using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WSConvertisseur.Models;

namespace WSConvertisseur.Controllers
{
    /// <summary>
    ///     Controller for devise
    /// </summary>
    [Produces("application/json")]
    [Route("api/Devise")]
    public class DeviseController : Controller
    {

        /// <summary>
        ///     Get all devise
        /// </summary>
        /// <returns>IEnumerable</returns>
        [HttpGet]
        [ProducesResponseType(typeof(IEnumerable<Devise>), 200)]
        public IEnumerable<Devise> GetAll()
        {
            return devises.AsEnumerable();
        }

        /// <summary>
        ///     Get a single currency.
        /// </summary>
        /// <returns>Http response</returns>
        /// <param name="id">The id of the currency</param>
        /// <response code="200">When the currency id is found</response>
        /// <response code="404">When the currency id is not found</response>
        [HttpGet("{id}", Name = "GetDevise")]
        [ProducesResponseType(typeof(Devise), 200)]
        [ProducesResponseType(404)]
        public IActionResult GetById(int id)
        {
            Devise devise = devises.FirstOrDefault((d) => d.Id == id);
            if(devise == null)
            {
                return NotFound();
            }
            return Ok(devise);
        }


        /// <summary>
        ///     Add a single currency.
        /// </summary>
        /// <returns>Http response</returns>
        /// <param name="devise">The devise</param>
        /// <response code="201">When the currency is added</response>
        /// <response code="400">When the parameter is not valid</response>
        [HttpPost]
        [ProducesResponseType(typeof(Devise), 201)]
        [ProducesResponseType(400)]
        public IActionResult Post([FromBody]Devise devise)
        {
            if(!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }
            devises.Add(devise);
            return CreatedAtRoute("GetDevise", new { id = devise.Id }, devise);
        }


        /// <summary>
        ///     Update a single currency.
        /// </summary>
        /// <returns>Http response</returns>
        /// <param name="id">The id of the currency</param>
        /// <param name="devise">The devise</param>
        /// <response code="204">When the currency id is found</response>
        /// <response code="400">When the parameter is not valid</response>
        /// <response code="404">When the currency id is not found</response>
        [HttpPut("{id}")]
        [ProducesResponseType(204)]
        [ProducesResponseType(400)]
        [ProducesResponseType(404)]
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


        /// <summary>
        ///     Delete a single currency.
        /// </summary>
        /// <returns>Http response</returns>
        /// <param name="id">The id of the currency</param>
        /// <response code="200">When the currency id is found and the deletion is OK</response>
        /// <response code="404">When the currency id is not found</response>
        [HttpDelete("{id}", Name = "DeleteDevise")]
        [ProducesResponseType(typeof(Devise), 200)]
        [ProducesResponseType(404)]
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

        /// <summary>
        ///     Constructor for the controller with list initialisation
        /// </summary>
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

        /// <summary>
        ///     list of devise
        /// </summary>
        private List<Devise> devises;
    }
}
