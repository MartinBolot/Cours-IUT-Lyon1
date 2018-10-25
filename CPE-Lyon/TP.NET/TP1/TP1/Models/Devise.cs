using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace WSConvertisseur.Models
{

    /// <summary>
    ///     Devise class
    /// </summary>
    public class Devise
    {
        /// <summary>
        ///     Id property
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        ///     Name of the devise
        /// </summary>
        [Required]
        public String NomDevise { get; set; }

        /// <summary>
        ///     Rate of the devise
        /// </summary>
        public Double Taux { get; set; }

        /// <summary>
        ///     Empty constructor
        /// </summary>
        public Devise(){}

        /// <summary>
        ///     constructor
        /// </summary>
        public Devise(int id, string nomDevise, double taux)
        {
            Id = id;
            NomDevise = nomDevise;
            Taux = taux;
        }

        /// <summary>
        ///  Vérifie l'égalité des objets
        /// </summary>
        /// <param name="obj">objet à comparer à l'objet courant (this)</param>
        /// <returns>bool</returns>
        public override bool Equals(object obj)
        {
            var devise = obj as Devise;
            return devise != null &&
                   Id == devise.Id &&
                   NomDevise == devise.NomDevise &&
                   Taux == devise.Taux;
        }

        public override int GetHashCode()
        {
            var hashCode = 1402098702;
            hashCode = hashCode * -1521134295 + Id.GetHashCode();
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(NomDevise);
            hashCode = hashCode * -1521134295 + Taux.GetHashCode();
            return hashCode;
        }
    }
}
