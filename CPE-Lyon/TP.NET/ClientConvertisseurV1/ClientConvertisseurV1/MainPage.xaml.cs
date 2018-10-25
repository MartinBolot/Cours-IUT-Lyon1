using ClientConvertisseurV1.Service;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Popups;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using WSConvertisseur.Models;

// Pour plus d'informations sur le modèle d'élément Page vierge, consultez la page https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace ClientConvertisseurV1
{
    /// <summary>
    /// Une page vide peut être utilisée seule ou constituer une page de destination au sein d'un frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();
            ActionGetData();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }
        private async void ActionGetData()
        {
            var result = await WSService.getAllDevisesAsync("devise");
            this.devise_value.DataContext = new List<Devise>(result);
        }

        private void bouton_Click(object sender, RoutedEventArgs e)
        {
            getMontantDeviseValue();
        }
        private async void getMontantDeviseValue()
        {
            double conversion = 0.0;
            bool noValue = string.IsNullOrEmpty(this.montant_euros_value.Text);
            bool noTarget = this.devise_value.SelectedValue == null;

            // if there is a problem
            if (noValue || noTarget)
            {
                string message = "";
                if (noValue)
                {
                    message = "A Euros value must be set";
                }
                else if(noTarget)
                {
                    message = "A target currency must be selected";
                }
                var messageDialog = new MessageDialog(message);
                messageDialog.Commands.Add(
                    new UICommand("Close")
                );
                messageDialog.DefaultCommandIndex = 0;
                await messageDialog.ShowAsync();
            }
            else
            {
                double montantEuros = Convert.ToDouble(this.montant_euros_value.Text);
                string selectedId = this.devise_value.SelectedValue.ToString();
                Devise deviseTo = await WSService.getDeviseByIdAsync("devise/" + selectedId);
                conversion = WSService.getConversion(deviseTo, montantEuros);
            }
            this.montant_devise_value.DataContext = conversion;
        }
    }
}
