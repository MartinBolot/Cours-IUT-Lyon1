using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace TP2Console.Models.EntityFramework
{
    public partial class Utilisateur
    {
        public override string ToString()
        {
            return string.Format("Utilisateur id : {0}, Login : {1}", Id, Login);
        }
    }
}
