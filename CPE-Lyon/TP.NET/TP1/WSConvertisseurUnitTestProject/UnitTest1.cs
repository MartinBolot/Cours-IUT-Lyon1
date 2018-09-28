using Microsoft.AspNetCore.Mvc;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using WSConvertisseur.Controllers;
using WSConvertisseur.Models;

namespace WSConvertisseurUnitTestProject
{
    [TestClass]
    public class UnitTest1
    {
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
        public void GetById_ExistingIdPassed_ReturnsOkObjectResult()
        {
            // Act
            var result = _controller.GetById(1);
            // Assert
            Assert.IsInstanceOfType(result, typeof(OkObjectResult), "Pas un OkObjectResult");
        }

        [TestMethod]
        public void GetById_ExistingIdPassed_ReturnsRightItem()
        {
            // Act
            var result = _controller.GetById(1) as OkObjectResult;
            // Assert
            Assert.IsInstanceOfType(result.Value, typeof(Devise), "Pas une Devise");
            Assert.AreEqual(
                new Devise(1, "Dollar", 1.08),
                (Devise)result.Value,
                "Devises pas identiques"
            );
}
        [TestMethod]
        public void GetById_UnknownGuidPassed_ReturnsNotFoundResult()
        {
            // Act
            var result = _controller.GetById(20);
            // Assert
            Assert.IsInstanceOfType(result, typeof(NotFoundResult), "Pas un NotFoundResult");
        }

        private DeviseController _controller;
    }
}
