using Microsoft.AspNetCore.Mvc;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;
using WSConvertisseur.Controllers;
using WSConvertisseur.Models;
using System.Linq;
using System.Threading.Tasks;

namespace WSConvertisseurUnitTestProject
{
    [TestClass]
    public class UnitTest1
    {
        private DeviseController _controller;

        [TestInitialize]
        public void InitialisationDesTests()
        {
            // initialisations
            // exécutées avant chaque test
            // Arrange
            _controller = new DeviseController();
        }

        [TestCleanup]
        public void NettoyageDesTests()
        {
            // Nettoyer les variables, ...
            // après chaque test
            _controller.Dispose();
        }

        [TestMethod]
        public async Task GetById_ExistingIdPassed_ReturnsOkObjectResult()
        {
            // Act
            var result = await _controller.GetById(1);
            // Assert
            Assert.IsInstanceOfType(result, typeof(OkObjectResult), "Pas un OkObjectResult");
        }

        [TestMethod]
        public async Task GetById_ExistingIdPassed_ReturnsRightItem()
        {
            // Act
            var result = await _controller.GetById(1) as OkObjectResult;
            // Assert
            Assert.IsInstanceOfType(result.Value, typeof(Devise), "Pas une Devise");
            Assert.AreEqual(
                new Devise(1, "Dollar", 1.08),
                (Devise)result.Value,
                "Devises pas identiques"
            );
        }
        [TestMethod]
        public async Task GetById_UnknownGuidPassed_ReturnsNotFoundResult()
        {
            // Act
            var result = await _controller.GetById(20);
            // Assert
            Assert.IsInstanceOfType(result, typeof(NotFoundResult), "Pas un NotFoundResult");
        }

        [TestMethod]
        public async Task GetAll()
        {
            // Act
            var result = await _controller.GetAll();
            // Assert
            Assert.IsInstanceOfType(result, typeof(List<Devise>), "Pas une List<Devise>");
        }
        
        [TestMethod]
        public async Task Post_WellFormedObjectPassed()
        {
            // Act
            var result = await _controller.Post(new Devise(4, "Euro", 1.15)) as CreatedAtRouteResult;
            List<Devise> list = (await _controller.GetAll()).ToList();
            // Assert
            Assert.IsInstanceOfType(result, typeof(CreatedAtRouteResult), "Pas un CreatedAtRouteResult");
            Assert.IsTrue(list.Contains((Devise)result.Value));
        }
        
        [TestMethod]
        public async Task Put_WellFormedObjectPassed()
        {
            // Act
            double newTaux = 1.09;
            var result = await _controller.Put(1, new Devise(1, "Dollar", newTaux)) as NoContentResult;
            var getById = await _controller.GetById(1) as OkObjectResult;
            Devise modifiedDevise = (Devise)getById.Value;
            // Assert
            Assert.IsInstanceOfType(result, typeof(NoContentResult), "Pas un NoContentResult");
            Assert.IsTrue(modifiedDevise.Taux == newTaux);
        }

        [TestMethod]
        public async Task DeleteById_ExistingIdPassed()
        {
            // Act
            int deviseId = 1;
            var originalDeviseResult = await _controller.GetById(deviseId) as OkObjectResult;
            var result = await _controller.DeleteById(deviseId) as OkObjectResult;
            Devise originalDevise = (Devise)originalDeviseResult.Value;
            Devise deletedDevise = (Devise)result.Value;

            // Assert
            Assert.IsInstanceOfType(result.Value, typeof(Devise), "Pas une Devise");
            Assert.AreEqual(
                originalDevise,
                deletedDevise,
                "Devises pas identiques"
            );
        }
    }
}
