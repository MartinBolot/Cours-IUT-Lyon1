using System;
using System.Linq;
using TP2Console.Models.EntityFramework;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;

namespace TP2Console
{
    class Program
    {
        static void Main(string[] args)
        {
            //Exo2Q1();
            //Exo2Q2();
            //Exo2Q3();
            Exo2Q4();
            /*
            Exo2Q5();
            Exo2Q6();
            Exo2Q7();
            Exo2Q8();
            Exo2Q9();
            */

            // attendre
            Console.ReadKey();
        }

        public static void Exo2Q4()
        {

            using (var ctx = new FilmsDBContext())
            {
                var actionCat = ctx.Categorie
                    .Include("Film")
                    .First(cat => cat.Nom == "Action");
                var films = actionCat.Film;
                foreach(var film in films)
                {
                    Console.WriteLine(film);
                }
            }
        }
        public static void Exo2Q5()
        {

        }
        public static void Exo2Q6()
        {

        }
        public static void Exo2Q7()
        {

        }
        public static void Exo2Q8()
        {

        }
        public static void Exo2Q9()
        {

        }

        /* done */
        public static void Exo2Q1()
        {
            var ctx = new FilmsDBContext();
            foreach (var film in ctx.Film)
            {
                Console.WriteLine(film.ToString());
            }
        }
        public static void Exo2Q2()
        {
            using (var ctx = new FilmsDBContext())
            {
                foreach(var user in ctx.Utilisateur)
                {
                    Console.WriteLine(user.Email);
                }
            }
        }
        public static void Exo2Q3()
        {
            using (var ctx = new FilmsDBContext())
            {
                var users = ctx.Utilisateur.OrderBy(user => user.Login);
                foreach (var user in users)
                {
                    Console.WriteLine(user);
                }
            }
        }
    }
}
