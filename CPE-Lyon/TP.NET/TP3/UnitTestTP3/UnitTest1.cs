using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Linq;
using System.Threading.Tasks;
using System.Collections.Generic;
using TP3.Controllers;
using TP3.Models.EntityFramework;
using TP3.Models.Repository;
using TP3.Models.DataManager;
using System;

namespace UnitTestTP3
{
    [TestClass]
    public class UnitTest1
    {
        public UnitTest1()
        {
            var builder = new DbContextOptionsBuilder<FilmsContext>()
                .UseSqlServer(
                "Server=localhost\\SQLEXPRESS; Database=Films;Trusted_Connection=True;"
            );

            context = new FilmsContext(builder.Options);
            _dataRepository = new CompteManager(context);
            compteController = new CompteController(_dataRepository);
        }

        [TestCleanup]
        public void NettoyageDesTests()
        {
            // Nettoyer les variables, ...
            // après chaque test
            compteController.Dispose();
            context.Dispose();
        }

        [TestMethod]
        public async Task TestGetCompteById()
        {
            var result = await compteController.GetCompteById(1) as OkObjectResult;
            var expectedCompte = context.Compte.Find(1);

            Assert.IsInstanceOfType(result, typeof(OkObjectResult));
            Assert.AreEqual(expectedCompte, (Compte)result.Value);
        }

        [TestMethod]
        public async Task TestGetCompteByEmail()
        {
            string email = "paul.durand@gmail.com";
            var result = await compteController.GetCompteByEmail(email) as OkObjectResult;
            var expectedCompte = context.Compte.Find(1);
            string expectedCompteEmail = expectedCompte.Mel;
            string actualCompteEmail = ((Compte)result.Value).Mel;

            Assert.IsInstanceOfType(result, typeof(OkObjectResult));
            Assert.AreEqual(expectedCompteEmail, actualCompteEmail);
        }

        [TestMethod]
        public async Task TestPostCompte()
        {
            Compte compte = new Compte();
            compte.Nom = "test";
            compte.Prenom = "test";
            compte.Mel = "test@test.com" + DateTime.Now;
            compte.Rue = "rue du test";
            compte.CodePostal = "69300";
            compte.Ville = "Caluire";
            compte.Pays = "TestLand";

            var result = await compteController.PostCompte(compte) as CreatedAtActionResult;
            Compte actualCompte = (Compte)result.Value;
            var expectedCompte = context.Compte.Find(actualCompte.CompteId);

            Assert.IsInstanceOfType(result, typeof(CreatedAtActionResult), "Bad result");
            Assert.AreEqual(expectedCompte, actualCompte);
        }

        private CompteController compteController;
        private FilmsContext context;
        private IDataRepository<Compte> _dataRepository;
    }
}
