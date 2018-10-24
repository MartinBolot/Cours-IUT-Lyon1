using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using TP3.Models.EntityFramework;

namespace TP3.Controllers
{
    [Produces("application/json")]
    [Route("api/Compte")]
    public class CompteController : Controller
    {
        private readonly FilmsContext _context;

        public CompteController(FilmsContext context)
        {
            _context = context;
        }

        // GET: api/Compte
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        [HttpGet]
        public IEnumerable<Compte> GetCompte()
        {
            return _context.Compte;
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

            var compte = await _context.Compte.SingleOrDefaultAsync(m => m.CompteId == id);

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

            var compte = await _context.Compte.SingleOrDefaultAsync(
                m => m.Mel.Equals(email)
            );

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

            _context.Entry(compte).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!CompteExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

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

            _context.Compte.Add(compte);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetCompte", new { id = compte.CompteId }, compte);
        }

        /*
        // DELETE: api/Compte/5
        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteCompte([FromRoute] int id)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var compte = await _context.Compte.SingleOrDefaultAsync(m => m.CompteId == id);
            if (compte == null)
            {
                return NotFound();
            }

            _context.Compte.Remove(compte);
            await _context.SaveChangesAsync();

            return Ok(compte);
        }
        */

        private bool CompteExists(int id)
        {
            return _context.Compte.Any(e => e.CompteId == id);
        }
    }
}