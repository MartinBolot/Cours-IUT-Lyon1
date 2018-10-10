using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace TP2Console.Models.EntityFramework
{
    public partial class Film
    {
        public override string ToString()
        {
            return string.Format("Film id : {0}, nom : {1}", Id, Nom);
        }
    }
}
