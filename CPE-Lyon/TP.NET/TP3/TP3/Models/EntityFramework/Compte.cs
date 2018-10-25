using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace TP3.Models.EntityFramework
{
    [Table("T_E_COMPTE_CPT")]
    public class Compte
    {
        public Compte()
        {
            AvisCompte = new HashSet<Avis>();
            FavoriCompte = new HashSet<Favori>();
        }

        [Column("CPT_ID")]
        public int CompteId { get; set; }

        [Column("CPT_NOM")]
        [Required]
        [StringLength(50)]
        public string Nom { get; set; }

        [Column("CPT_PRENOM")]
        [Required]
        [StringLength(50)]
        public string Prenom { get; set; }

        [Column("CPT_TELPORTABLE", TypeName="char(50)")]
        public string TelPortable { get; set; }

        [Column("CPT_MEL")]
        [Required]
        [StringLength(100)]
        public string Mel { get; set; }

        [Column("CPT_PWD")]
        [StringLength(64)]
        public string Pwd { get; set; }

        [Column("CPT_RUE")]
        [Required]
        [StringLength(200)]
        public string Rue { get; set; }

        [Column("CPT_CP", TypeName = "char(5)")]
        [Required]
        public string CodePostal { get; set; }

        [Column("CPT_VILLE")]
        [Required]
        [StringLength(50)]
        public string Ville { get; set; }

        [Column("CPT_PAYS")]
        [Required]
        [StringLength(50)]
        public string Pays { get; set; }

        [Column("CPT_LATITUDE", TypeName=("real"))]
        public float? Latitude { get; set; }

        [Column("CPT_LONGITUDE", TypeName = ("real"))]
        public float? Longitude { get; set; }

        // Propriétés de navigation vers Avis et Favori.
        [InverseProperty("CompteAvis")]
        public ICollection<Avis> AvisCompte { get; set; }
        [InverseProperty("CompteFavori")]
        public ICollection<Favori> FavoriCompte { get; set; }

    }
}
