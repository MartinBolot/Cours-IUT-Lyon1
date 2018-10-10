using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace TP2Console.Models.EntityFramework
{
    public partial class Film
    {
        public Film()
        {
            Avis = new HashSet<Avis>();
        }

        [Column("id")]
        public int Id { get; set; }
        [Required]
        [Column("nom")]
        [StringLength(50)]
        public string Nom { get; set; }
        [Column("description", TypeName = "text")]
        public string Description { get; set; }
        [Column("categorie")]
        public int Categorie { get; set; }

        [ForeignKey("Categorie")]
        [InverseProperty("Film")]
        public Categorie CategorieNavigation { get; set; }
        [InverseProperty("FilmNavigation")]
        public ICollection<Avis> Avis { get; set; }
    }
}
