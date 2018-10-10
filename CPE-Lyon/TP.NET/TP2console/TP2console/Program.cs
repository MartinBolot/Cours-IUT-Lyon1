using System;
using System.Linq;
using TP2Console.Models.EntityFramework;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;
using System.Collections.Generic;

namespace TP2Console
{
    class Program
    {
        static void Main(string[] args)
        {
            //Exo2Q1();
            //Exo2Q2();
            //Exo2Q3();
            //Exo2Q4();
            //Exo2Q5();
            //Exo2Q6();
            //Exo2Q7();
            //Exo2Q8();
            //Exo2Q9();

            //AddMyUser();
            //modifyFilm();
            //deleteFilm();
            //AddAvis();
            AddFilms();


            // attendre
            Console.ReadKey();
        }

        public static FilmsDBContext ctx = new FilmsDBContext();

        // Ajouter 2 films dans la catégorie « Drame ».
        // Utiliser AddRange().
        public static void AddFilms()
        {
            string categorie = "Drame";
            var categorieId = ctx.Categorie
                .Where(c => c.Nom.ToLower().Equals(categorie.ToLower()))
                .Select(c => c.Id)
                .First();
            List<Film> filmList = new List<Film>();
            Film film1 = new Film();
            Film film2 = new Film();
            film1.Categorie = categorieId;
            film1.Nom = "La reine des neiges";
            film1.Description = "Une fille dans la neige";
            film2.Categorie = categorieId;
            film2.Nom = "Le roi lion";
            film2.Description = "Un lion dans la savane";
            filmList.Add(film1);
            filmList.Add(film2);

            ctx.Film.AddRange(filmList);

            ctx.SaveChanges();
        }

        // Ajouter votre avis et note à votre film préféré (ou détesté).
        public static void AddAvis()
        {
            Avis avis = new Avis();
            avis.Film = 3;
            avis.Utilisateur = 642;
            avis.Avis1 = "infame";
            avis.Note = 0;

            ctx.Avis.Add(avis);

            ctx.SaveChanges();
        }

        // Supprimer le film « L'armee des douze singes ».
        // Note : il n’y a pas de delete cascade sur la foreign key.
        // Penser à supprimer les Avis associés !
        public static void deleteFilm()
        {
            string title = "L'armee des douze singes";
            var film = ctx.Film
                .Where(f => f.Nom.ToLower() == title.ToLower()).First();
            var avis = ctx.Avis
                .Where(a => a.FilmNavigation.Equals(film));

            ctx.Avis.RemoveRange(avis);
            ctx.Film.Remove(film);

            ctx.SaveChanges();
        }

        // Rajouter une description au film « L'armee des douze singes »
        // et le mettre dans la catégorie « Drame ».
        public static void modifyFilm()
        {
            string title = "L'armee des douze singes";
            string categorie = "Drame";
            var film = ctx.Film
                .Where(f => f.Nom.ToLower() == title.ToLower()).First();
            var drameCategorie = ctx.Categorie
                .Where(c => c.Nom.ToLower() == categorie.ToLower())
                .Select(c => c.Id)
                .First();
            
            if(film != null && categorie != null)
            {
                film.Description = "testdescription";
                film.Categorie = drameCategorie;
            }

            ctx.SaveChanges();
        }
        // ajout d'un utilisateur
        public static void AddMyUser()
        {
            Utilisateur user = new Utilisateur();
            user.Login = "Martin";
            user.Email = "test@test.com";
            user.Pwd = "testtest";

            ctx.Utilisateur.Add(user);

            ctx.SaveChanges();
        }

        /* done */
        // ex 1
        public static void Exo2Q1()
        {
            using (var ctx = new FilmsDBContext())
            {
                foreach (var film in ctx.Film)
                {
                    Console.WriteLine(film.ToString());
                }
            }
        }
        // Afficher les emails de tous les utilisateurs.
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
        // Afficher tous les utilisateurs triés par login croissant.
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
        // Afficher les noms et id des films de la catégorie « Action ».
        public static void Exo2Q4()
        {
            using (var ctx = new FilmsDBContext())
            {
                var actionCat = ctx.Categorie
                    .Include("Film")
                    .First(cat => cat.Nom == "Action");
                var films = actionCat.Film;
                foreach (var film in films)
                {
                    Console.WriteLine(
                        string.Format("Nom du film : {0}, id : {1}", film.Nom, film.Id)
                    );
                }
            }
        }
        // Afficher le nombre de catégories.
        public static void Exo2Q5()
        {
            using (var ctx = new FilmsDBContext())
            {
                var categories = ctx.Categorie;
                var nbCategories = ctx.Categorie.Count();

                Console.WriteLine("Nombre de catégories : " + nbCategories);
            }
        }
        // Afficher la note la plus basse dans la base.
        public static void Exo2Q6()
        {
            using (var ctx = new FilmsDBContext())
            {
                var noteMin = ctx.Avis.Select(avis => avis.Note).Min();

                Console.WriteLine("Note la plus basse : " + noteMin);
            }
        }
        // Rechercher tous les films qui commencent par « ve » (pas de respect de la casse).
        public static void Exo2Q7()
        {
            using (var ctx = new FilmsDBContext())
            {
                string pattern = "le";
                // le nom du film n'est pas nullable
                var matchedFilms = ctx.Film
                    .Where(f => f.Nom.ToLower().StartsWith(pattern.ToLower()));

                foreach (var film in matchedFilms)
                {
                    Console.WriteLine(film);
                }
            }
        }
        // Afficher la note moyenne du film « Pulp Fiction »
        // (note : le nom du film ne devra pas être sensible à la casse).
        public static void Exo2Q8()
        {
            using (var ctx = new FilmsDBContext())
            {
                string nomFilm = "Pulp Fiction";
                // le nom du film n'est pas nullable
                var matchedAvis = ctx.Avis
                    .Include(a => a.FilmNavigation)
                    .ToList();
                var filteredAvis = matchedAvis
                    .Where(
                        a => a.FilmNavigation.Nom.ToLower().Equals(nomFilm.ToLower())
                    );
                var meanAvis = filteredAvis.Select(a => a.Note).Average();

                Console.WriteLine(meanAvis);

            }
        }
        // Afficher l’utilisateur qui a mis la meilleure note dans la base
        // (on pourra le faire en 2 instructions, mais essayer de le faire en une seule).
        public static void Exo2Q9()
        {
            using (var ctx = new FilmsDBContext())
            {
                // TODO faire en 1 instruction
                var bestNote = ctx.Avis
                    .Where(a => a.Note == ctx.Avis.Select(avis => avis.Note).Max())
                    .First();
                var userBestNote = ctx.Utilisateur
                    .Where(u => u.Id == bestNote.Utilisateur)
                    .First();

                Console.WriteLine(userBestNote);
            }
        }
    }
}
