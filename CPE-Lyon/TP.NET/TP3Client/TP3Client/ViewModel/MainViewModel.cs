using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TP3Client.Models;
using TP3Client.Service;
using System.Windows.Input;
using GalaSoft.MvvmLight.Command;
using Windows.UI.Popups;
using TP3Client.View;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml;

namespace TP3Client.ViewModel
{
    public abstract class MainViewModel : ViewModelBase
    {
        public MainViewModel()
        {
            ActionGetData();
            BtnSetConversion = new RelayCommand(ActionSetConversion);
        }

        /*
        public ObservableCollection<Devise> ComboBoxDevises
        {
            get { return _comboBoxDevises; }
            set
            {
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
        */

        public string NomResult
        {
            get { return _nomResult; }
            set
            {
                _nomResult = value;
                RaisePropertyChanged();
            }
        }
        protected string _nomResult;

        public ICommand BtnSetConversion { get; private set; }

        protected async void ActionGetData()
        {
            //var result = await WSService.GetCompteByEmail("paul.durand@gmail.com");
            //this.NomResult = new ObservableCollection<Compte>(result);
        }
        protected abstract void ActionSetConversion();

        public void ActionChangeGetByEmail()
        {
            GetEmailPage r = (GetEmailPage)Window.Current.Content;
            SplitView sv = (SplitView)(r.Content);
            (sv.Content as Frame).Navigate(typeof(MainPage));
        }
    }
}