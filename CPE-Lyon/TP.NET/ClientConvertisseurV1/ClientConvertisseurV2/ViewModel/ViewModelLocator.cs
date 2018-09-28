using GalaSoft.MvvmLight.Ioc;
using CommonServiceLocator;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClientConvertisseurV2.ViewModel
{
    /// <summary>
    /// This class contains static references to all the view models in the
    /// application and provides an entry point for the bindings.
    /// <para>
    /// See http://www.mvvmlight.net
    /// </para>
    /// </summary>
    public class ViewModelLocator
    {
        static ViewModelLocator()
        {
            ServiceLocator.SetLocatorProvider(() => SimpleIoc.Default);
            SimpleIoc.Default.Register<EurosToCurrencyViewModel>();
            SimpleIoc.Default.Register<CurrencyToEurosViewModel>();
        }

        /// <summary>
        /// Gets the EurosToCurrencyViewModel property.
        /// </summary>
        public EurosToCurrencyViewModel Main => ServiceLocator.Current.GetInstance<EurosToCurrencyViewModel>();
        /// <summary>
        /// Gets the CurrencyToEuros property.
        /// </summary>
        public CurrencyToEurosViewModel CurrencyToEuros => ServiceLocator.Current.GetInstance<CurrencyToEurosViewModel>();
    }
}
