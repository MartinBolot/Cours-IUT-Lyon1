using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using WSConvertisseur.Models;

namespace ClientConvertisseurV1.Service
{
    class WSService
    {
        static HttpClient client = new HttpClient();
        private static Uri baseUri = new Uri("http://localhost:1681/api/");

        /// <summary>
        ///     get all devise
        /// </summary>
        /// <returns>List Devise</returns>
        public static async Task<List<Devise>> getAllDevisesAsync(string path)
        {
            List<Devise> devises = null;
            Uri uri = new Uri(baseUri.AbsoluteUri + path);
            HttpResponseMessage response = await client.GetAsync(uri);
            if (response.IsSuccessStatusCode)
            {
                devises = await response.Content.ReadAsAsync<List<Devise>>();
            }
            return devises;
        }

        /// <summary>
        ///     get one devise
        /// </summary>
        /// <returns>Devise</returns>
        public static async Task<Devise> getDeviseByIdAsync(string path)
        {
            Devise devise = null;
            Uri uri = new Uri(baseUri.AbsoluteUri + path);
            HttpResponseMessage response = await client.GetAsync(uri);
            if (response.IsSuccessStatusCode)
            {
                devise = await response.Content.ReadAsAsync<Devise>();
            }
            return devise;
        }

        public static async Task<Uri> CreateDeviseAsync(Devise devise)
        {
            HttpResponseMessage response = await client.PostAsJsonAsync(
                "devise", devise);
            response.EnsureSuccessStatusCode();

            // return URI of the created resource.
            return response.Headers.Location;
        }

        public static async Task<Devise> UpdateDeviseAsync(Devise devise)
        {
            HttpResponseMessage response = await client.PutAsJsonAsync(
                $"api/devise/{devise.Id}", devise);
            response.EnsureSuccessStatusCode();

            // Deserialize the updated product from the response body.
            devise = await response.Content.ReadAsAsync<Devise>();
            return devise;
        }

        public static async Task<HttpStatusCode> DeleteDeviseAsync(string id)
        {
            HttpResponseMessage response = await client.DeleteAsync(
                $"api/devise/{id}");
            return response.StatusCode;
        }

        /* tests
        static void Main()
        {
            RunAsync().GetAwaiter().GetResult();
        }
        static async Task RunAsync()
        {
            // Update port # in the following line.
            client.BaseAddress = new Uri("http://localhost:1681/api/");
            client.DefaultRequestHeaders.Accept.Clear();
            client.DefaultRequestHeaders.Accept.Add(
                new MediaTypeWithQualityHeaderValue("application/json"));

            try
            {
                // Create a new product
                Devise devise = new Devise
                {
                    Name = "Gizmo",
                    Price = 100,
                    Category = "Widgets"
                };

                var url = await CreateProductAsync(product);
                Console.WriteLine($"Created at {url}");

                // Get the product
                product = await GetProductAsync(url.PathAndQuery);
                ShowProduct(product);

                // Update the product
                Console.WriteLine("Updating price...");
                product.Price = 80;
                await UpdateProductAsync(product);

                // Get the updated product
                product = await GetProductAsync(url.PathAndQuery);
                ShowProduct(product);

                // Delete the product
                var statusCode = await DeleteProductAsync(product.Id);
                Console.WriteLine($"Deleted (HTTP Status = {(int)statusCode})");

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.ReadLine();
        }
        */
        /// <summary>
        ///     Converte a value to a give devise
        /// </summary>
        /// <param name="deviseTo">target devise</param>
        /// <param name="valueEuro">value in euro</param>
        /// <returns>double</returns>
        public static double getConversion(Devise deviseTo, double valueEuro)
        {
            double conversion = 0.0;
            if(deviseTo == null)
            {
                throw new Exception("Null devise argument");
            }
            conversion = deviseTo.Taux * valueEuro;
            return conversion;
        }
    }
}
