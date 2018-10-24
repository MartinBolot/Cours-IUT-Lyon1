using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3.Models.EntityFramework
{
    [Table("T_J_FAVORI_FAV")]
    public class Favori
    {
        public Favori()
        {
            CompteFavori = new Compte();
            FilmFavori = new Film();
        }
        
        [Column("CPT_ID")]
        [ForeignKey("Compte")]
        public int CompteId { get; set; }
        
        [Column("FLM_ID")]
        [ForeignKey("Film")]
        public int FilmId { get; set; }

        //Propriétés de navigation vers Compte et Film.
        // Les nommer CompteFavori et FilmFavori.
        [InverseProperty("FavoriCompte")]
        public Compte CompteFavori { get; set; }

        [InverseProperty("FavoriFilm")]
        public Film FilmFavori { get; set; }
    }
}
