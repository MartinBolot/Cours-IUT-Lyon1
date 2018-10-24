using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3.Models.EntityFramework
{
    [Table("T_E_FILM_FLM")]
    public class Film
    {
        public Film()
        {
            AvisFilm = new HashSet<Avis>();
            FavoriFilm = new HashSet<Favori>();
        }

        [Column("FLM_ID")]
        public int FilmId { get; set; }

        [Column("FLM_TITRE")]
        [Required]
        [StringLength(100)]
        public string Titre { get; set; }

        [Column("FLM_SYNOPSIS")]
        [StringLength(500)]
        public string Synopsis { get; set; }

        [Column("FLM_DATEPARUTION")]
        public DateTime DateParution { get; set; }

        [Column("FLM_DUREE", TypeName="numeric(3,0)")]
        [Required]
        public decimal Duree { get; set; }

        [Column("FLM_GENRE")]
        [Required]
        [StringLength(30)]
        public string Genre { get; set; }

        [Column("FLM_URLPHOTO")]
        [StringLength(200)]
        public string UrlPhoto { get; set; }

        // Propriétés de navigation vers Avis et Favori
        [InverseProperty("FilmAvis")]
        public ICollection<Avis> AvisFilm { get; set; }
        [InverseProperty("FilmFavori")]
        public ICollection<Favori> FavoriFilm { get; set; }

    }
}
