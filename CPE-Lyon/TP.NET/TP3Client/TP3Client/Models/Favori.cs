using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3Client.Models
{
    public class Favori
    {
        public Favori()
        {
            CompteFavori = new Compte();
            FilmFavori = new Film();
        }
        
        public int CompteId { get; set; }
        
        public int FilmId { get; set; }
        
        public Compte CompteFavori { get; set; }
        
        public Film FilmFavori { get; set; }
    }
}
