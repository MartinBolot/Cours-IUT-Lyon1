using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using TP3.Models.DataManager;
using TP3.Models.EntityFramework;
using TP3.Models.Repository;

namespace TP3.Controllers
{
    [Produces("application/json")]
    [Route("api/Compte")]
    public class CompteController : Controller
    {
        private readonly IDataRepository<Compte> _dataRepository;
        
        public CompteController(IDataRepository<Compte> dataRepository)
        {
            _dataRepository = dataRepository;
        }

        // GET: api/Compte
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [HttpGet]
        public async Task<IEnumerable<Compte>> GetCompte()
        {
            return await _dataRepository.GetAll();
        }

        // GET: api/Compte/5
        /// <summary>
        /// 
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        [HttpGet("GetCompteById/{id}")]
        public async Task<IActionResult> GetCompteById([FromRoute] int id)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var compte = await _dataRepository.GetById(id);

            if (compte == null)
            {
                return NotFound();
            }

            return Ok(compte);
        }

        // GET: api/Compte/test@test.com
        /// <summary>
        /// 
        /// </summary>
        /// <param name="email"></param>
        /// <returns></returns>
        [HttpGet("GetCompteByEmail/{email}")]
        public async Task<IActionResult> GetCompteByEmail([FromRoute] string email){
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var compte = await _dataRepository.GetByString(email);

            if (compte == null)
            {
                return NotFound();
            }

            return Ok(compte);
        }

        // PUT: api/Compte/5
        /// <summary>
        /// 
        /// </summary>
        /// <param name="id"></param>
        /// <param name="compte"></param>
        /// <returns></returns>
        [HttpPut("{id}")]
        public async Task<IActionResult> PutCompte([FromRoute] int id, [FromBody] Compte compte)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            if (id != compte.CompteId)
            {
                return BadRequest();
            }

            var compteToUpdate = await _dataRepository.GetById(id);

            if (compteToUpdate == null)
            {
                return NotFound();
            }

            _dataRepository.Update(compteToUpdate, compte);

            return NoContent();
        }

        // POST: api/Compte
        /// <summary>
        /// 
        /// </summary>
        /// <param name="compte"></param>
        /// <returns></returns>
        [HttpPost]
        public async Task<IActionResult> PostCompte([FromBody] Compte compte)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            _dataRepository.Add(compte);

            return CreatedAtAction("GetCompteById", new { id = compte.CompteId }, compte);
        }

        // DELETE: api/Compte/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteCompte([FromRoute] int id)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var compte = await _dataRepository.GetById(id);
            if (compte == null)
            {
                return NotFound();
            }

            _dataRepository.Delete(compte);

            return Ok(compte);
        }

        /*
        private bool CompteExists(int id)
        {
            return _context.Compte.Any(e => e.CompteId == id);
        }
        */
    }
}