using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI.Popups;

namespace ClientConvertisseurV2.ViewModel
{
    public class CurrencyToEurosViewModel : MainViewModel
    {
        override protected async void ActionSetConversion()
        {
            double result = 0.0;
            bool tryparse = double.TryParse(_montantDevises, out result);
            if (tryparse && _comboBoxDeviseItem != null)
            {
                if(_comboBoxDeviseItem.Taux == 0)
                {
                    result = 0.0;
                }
                else
                {
                    result = result / _comboBoxDeviseItem.Taux;
                }
            }
            if (!tryparse || _comboBoxDeviseItem == null)
            {

                string message = "";
                if (!tryparse)
                {
                    message = "A devises value must be set";
                }
                else if (_comboBoxDeviseItem == null)
                {
                    message = "A source currency must be selected";
                }
                var messageDialog = new MessageDialog(message);
                messageDialog.Commands.Add(
                    new UICommand("Close")
                );
                messageDialog.DefaultCommandIndex = 0;
                await messageDialog.ShowAsync();
            }
            this.DeviseResult = result.ToString();
        }
    }
}
