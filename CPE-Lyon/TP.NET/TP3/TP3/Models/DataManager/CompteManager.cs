using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using TP3.Models.EntityFramework;
using TP3.Models.Repository;
using Microsoft.EntityFrameworkCore;

namespace TP3.Models.DataManager
{
    public class CompteManager : IDataRepository<Compte>
    {
        readonly FilmsContext _filmRatingsDbContext;
        public CompteManager(FilmsContext context)
        {
            _filmRatingsDbContext = context;
        }
        public async Task<IEnumerable<Compte>> GetAll()
        {
            return _filmRatingsDbContext.Compte.ToList();
        }
        public async Task<Compte> GetById(int id)
        {
            return await _filmRatingsDbContext.Compte
            .FirstOrDefaultAsync(e => e.CompteId == id);
        }
        public async Task<Compte> GetByString(string mail)
        {
            return await _filmRatingsDbContext.Compte
            .FirstOrDefaultAsync(e => e.Mel.ToUpper() == mail.ToUpper());
        }
        public void Add(Compte entity)
        {
            _filmRatingsDbContext.Compte.Add(entity);
            _filmRatingsDbContext.SaveChanges();
        }
        public void Update(Compte compte, Compte entity)
        {
            compte.CompteId = entity.CompteId;
            compte.Nom = entity.Nom;
            compte.Prenom = entity.Prenom;
            compte.Mel = entity.Mel;
            compte.Rue = entity.Rue;
            compte.CodePostal = entity.CodePostal;
            compte.Ville = entity.Ville;
            compte.Pays = entity.Pays;
            compte.Latitude = entity.Latitude;
            compte.Longitude = entity.Longitude;
            compte.Pwd = entity.Pwd;
            compte.TelPortable = entity.TelPortable;
            compte.AvisCompte = entity.AvisCompte;
            compte.FavoriCompte = entity.FavoriCompte;
            _filmRatingsDbContext.SaveChanges();
        }
        public void Delete(Compte compte)
        {
            _filmRatingsDbContext.Compte.Remove(compte);
            _filmRatingsDbContext.SaveChanges();
        }
    }
}
