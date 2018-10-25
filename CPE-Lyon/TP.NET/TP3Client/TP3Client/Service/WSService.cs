using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Threading.Tasks;
using TP3Client.Models;

namespace TP3Client.Service
{
    class WSService
    {
        static HttpClient client = new HttpClient();
        private static Uri baseUri = new Uri("http://localhost:1681/api/");

        /// <summary>
        ///     get compte by email
        /// </summary>
        /// <returns>Compte</returns>
        public static async Task<Compte> GetCompteByEmail(string email)
        {
            Compte compte = null;
            Uri uri = new Uri(baseUri.AbsoluteUri + "compte/getcomptebyemail/" + email);
            HttpResponseMessage response = await client.GetAsync(uri);
            if (response.IsSuccessStatusCode)
            {
                compte = await response.Content.ReadAsAsync<Compte>();
            }
            return compte;
        }

        /*
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
                */

    }
}