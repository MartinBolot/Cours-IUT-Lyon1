using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WSConvertisseurV2.Model;
using ClientConvertisseurV2.Service;
using System.Windows.Input;
using GalaSoft.MvvmLight.Command;
using Windows.UI.Popups;
using ClientConvertisseurV2.View;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml;

namespace ClientConvertisseurV2.ViewModel
{
    public abstract class MainViewModel : ViewModelBase
    {
        public MainViewModel()
        {
            ActionGetData();
            BtnSetConversion = new RelayCommand(ActionSetConversion);
        }
    
        public ObservableCollection<Devise> ComboBoxDevises
        {
            get { return _comboBoxDevises; }
            set {
                _comboBoxDevises = value;
                RaisePropertyChanged();
            }
        }
        public Devise ComboBoxDeviseItem
        {
            get { return _comboBoxDeviseItem; }
            set
            {
                _comboBoxDeviseItem = value;
                RaisePropertyChanged();
            }
        }
        public string MontantEuros
        {
            get { return _montantEuros; }
            set
            {
                _montantEuros = value;
                RaisePropertyChanged();
            }
        }
        public string MontantDevises
        {
            get { return _montantDevises; }
            set
            {
                _montantDevises = value;
                RaisePropertyChanged();
            }
        }
        public string DeviseResult
        {
            get { return _deviseResult; }
            set
            {
                _deviseResult = value;
                RaisePropertyChanged();
            }
        }

        public ICommand BtnSetConversion { get; private set; }

        protected async void ActionGetData()
        {
            var result = await WSService.getAllDevisesAsync("devise");
            this.ComboBoxDevises = new ObservableCollection<Devise>(result);
        }
        protected abstract void ActionSetConversion();

        public void ActionChangeConvertisseur()
        {
            RootPage r = (RootPage)Window.Current.Content;
            SplitView sv = (SplitView)(r.Content);
            (sv.Content as Frame).Navigate(typeof(MainPage));
        }

        protected ObservableCollection<Devise> _comboBoxDevises;
        protected Devise _comboBoxDeviseItem;
        protected string _montantEuros;
        protected string _montantDevises;
        protected string _deviseResult;


    }
}
