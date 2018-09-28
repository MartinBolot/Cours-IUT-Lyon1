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
        public Devise()
        {

        }
    }
}
