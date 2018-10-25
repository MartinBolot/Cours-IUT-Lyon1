using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3Client.Models
{
    public class Compte
    {
        public Compte()
        {
            AvisCompte = new HashSet<Avis>();
            FavoriCompte = new HashSet<Favori>();
        }
        
        public int CompteId { get; set; }
        
        public string Nom { get; set; }

        public string Prenom { get; set; }
        
        public string TelPortable { get; set; }
        
        public string Mel { get; set; }
        
        public string Pwd { get; set; }
        
        public string Rue { get; set; }
        
        public string CodePostal { get; set; }

        public string Ville { get; set; }

        public string Pays { get; set; }
        
        public float? Latitude { get; set; }
        
        public float? Longitude { get; set; }
        
        public ICollection<Avis> AvisCompte { get; set; }
        public ICollection<Favori> FavoriCompte { get; set; }

    }
}
