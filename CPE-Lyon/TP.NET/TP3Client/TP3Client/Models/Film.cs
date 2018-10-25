using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3Client.Models {
    public class Film
    {
        public Film()
        {
            AvisFilm = new HashSet<Avis>();
            FavoriFilm = new HashSet<Favori>();
        }
        
        public int FilmId { get; set; }
        
        public string Titre { get; set; }
        
        public string Synopsis { get; set; }
        
        public DateTime DateParution { get; set; }

        public decimal Duree { get; set; }
        
        public string Genre { get; set; }
        
        public string UrlPhoto { get; set; }
        
        public ICollection<Avis> AvisFilm { get; set; }

        public ICollection<Favori> FavoriFilm { get; set; }

    }
}
