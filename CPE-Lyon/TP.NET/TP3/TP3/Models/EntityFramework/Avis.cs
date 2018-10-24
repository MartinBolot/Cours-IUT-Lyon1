using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3.Models.EntityFramework
{
    [Table("T_E_AVIS_AVI")]
    public class Avis
    {
        public Avis()
        {
            CompteAvis = new Compte();
            FilmAvis = new Film();
        }
        
        [Column("CPT_ID")]
        [ForeignKey("Compte")]
        public int CompteId { get; set; }
        
        [Column("FLM_ID")]
        [ForeignKey("Film")]
        public int FilmId { get; set; }

        [Column("AVI_DATE")]
        [Required]
        public DateTime DateAvis { get; set; }

        [Column("AVI_TITRE")]
        [Required]
        [StringLength(100)]
        public string Titre { get; set; }

        [Column("AVI_DETAIL")]
        [Required]
        [StringLength(2000)]
        public string Detail { get; set; }

        [Column("AVI_NOTE", TypeName="numeric(1)")]
        [Required]
        public decimal Note { get; set; }

        // Propriétés de navigation vers Compte et Film.
        // Les nommer CompteAvis et FilmAvis.
        [InverseProperty("AvisCompte")]
        public Compte CompteAvis { get; set; }

        [InverseProperty("AvisFilm")]
        public Film FilmAvis { get; set; }
    }
}
