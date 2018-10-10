using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace TP2Console.Models.EntityFramework
{
    public partial class Categorie
    {
        public override string  ToString()
        {
            return string.Format("Categorie id : {0}", Id);
        }
    }
}
