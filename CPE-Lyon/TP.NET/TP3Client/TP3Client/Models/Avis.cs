using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3Client.Models
{
    public class Avis
    {
        public Avis()
        {
            CompteAvis = new Compte();
            FilmAvis = new Film();
        }
        
        public int CompteId { get; set; }
        
        public int FilmId { get; set; }
        
        public DateTime DateAvis { get; set; }
        
        public string Titre { get; set; }
        
        public string Detail { get; set; }
        
        public decimal Note { get; set; }
        
        public Compte CompteAvis { get; set; }
        
        public Film FilmAvis { get; set; }
    }
}
