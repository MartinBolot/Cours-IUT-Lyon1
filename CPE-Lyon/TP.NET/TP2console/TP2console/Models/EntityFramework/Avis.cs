using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace TP2Console.Models.EntityFramework
{
    public partial class Avis
    {
        [Column("film")]
        public int Film { get; set; }
        [Column("utilisateur")]
        public int Utilisateur { get; set; }
        [Column("avis", TypeName = "text")]
        public string Avis1 { get; set; }
        [Column("note")]
        public double Note { get; set; }

        [ForeignKey("Film")]
        [InverseProperty("Avis")]
        public Film FilmNavigation { get; set; }
        [ForeignKey("Utilisateur")]
        [InverseProperty("Avis")]
        public Utilisateur UtilisateurNavigation { get; set; }
    }
}
