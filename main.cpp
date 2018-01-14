#include <iostream>
#include "assets/investment/Investment.h"
#include "wallet/Wallet.cpp"
#include<fstream>

using namespace std;
bool run;

void displayNewAssetForm(Wallet<Asset> & wallet, int choice, ofstream & sv){
    switch (choice) {
        case 1: {
            auto *investment = new Investment();
            wallet.addAsset(investment);
            break;
        }
        case 2: {
            auto *contract = new Contract();
            wallet.addAsset(contract);
            break;
        }
        case 3: {
            auto *propertyRental = new PropertyRental();
            wallet.addAsset(propertyRental);
            break;
        }
        case 4: {
            auto *bitcoin = new Crypto();
            wallet.addAsset(bitcoin);
            break;
        }
        case 5: {
            auto *fundUnit = new FundUnit();
            wallet.addAsset(fundUnit);
            break;
        }
        case 6: {
            auto *fundUnitDividend = new FundUnitDividend();
            wallet.addAsset(fundUnitDividend);
            break;
        }
        default:
            break;
    }
    wallet.save(sv);
}

void displayWalletStateMenu(Wallet<Asset> & wallet){
    int choice;
    cout<<"Co chcesz zrobic?"<<endl;
    cout<<"1 Wyswietl aktualny stan oszczednosci"<<endl;
    cout<<"2 Wyswietl ile uzyskam pieniedzy po X miesiacach"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            wallet.displayAllAssets();
            break;
        case 2: {
            int months;
            cout << "Podaj dlugosc okresu symulacji w miesiacach" << endl;
            cin>>months;
                wallet.displayValueAfter(months);
            }
            break;
        default:
            break;
    }
}

void displayNewAssetMenu(Wallet<Asset> & wallet, ofstream & sv){
    int choice;
    cout<<"Wybierz jaki rodzaj aktywa chcesz dodać:"<<endl;
    cout<<"1 Lokata"<<endl;
    cout<<"2 Kontrakt"<<endl;
    cout<<"3 Wynajem nieruchomosci"<<endl;
    cout<<"4 Kryptowaluty"<<endl;
    cout<<"5 Jednostka funduszu bez dywidendy"<<endl;
    cout<<"6 Jednostka funduszu z dywidenda"<<endl;
    cin>>choice;
    displayNewAssetForm(wallet, choice, sv);
}

void displayDeleteMenu(Wallet<Asset> & wallet, ofstream & sv){
    int choice;
    cout<<"W portfelu znajduja sie nastepujace aktywa"<<endl;
    wallet.displayAllAssets();
    cout<<"Podaj indeks aktywa ktore chcesz usunac"<<endl;
    cin>>choice;
    wallet.removeAsset(choice);
    wallet.save(sv);
}

void displayEditMenu(Wallet<Asset> & wallet, ofstream & sv){
    int choice1, choice2;
    cout<<"Chcesz zmienic wartosci wszystkich pol aktywa czy tylko zmienic jego ilosc?"<<endl;
    cout<<"1 Zmienic wszystkie wartosci pol"<<endl;
    cout<<"2 Zmienic ilosc aktywa"<<endl;
    cin>>choice1;
    cout<<"W portfelu znajduja sie nastepujace aktywa"<<endl;
    wallet.displayAllAssets();
    cout<<"Podaj indeks aktywa ktore chcesz edytowac"<<endl;
    cin>>choice2;
    if(choice1 == 1){
        wallet.editWholeAsset(choice2);
    }
    else{
        wallet.editAmount(choice2);
    }
    wallet.save(sv);
}

void forwardMenuOptions(Wallet<Asset> & wallet, int choice, ofstream & sv){
    switch(choice){
        case 1:
            displayNewAssetMenu(wallet, sv);
            break;
        case 2:
            displayDeleteMenu(wallet, sv);
            break;
        case 3:
            displayEditMenu(wallet, sv);
            break;
        case 4:
            displayWalletStateMenu(wallet);
            break;
        case 5:
            run = false;
        default:
            break;
    }
}

void displayMainMenu(Wallet<Asset> & wallet, ofstream & sv){
    int choice;
    cout<<"Wybierz co chcesz zrobic:"<<endl;
    cout<<"1 Dodaj nowe aktywo"<<endl;
    cout<<"2 Usun aktywo"<<endl;
    cout<<"3 Edytuj aktywo"<<endl;
    cout<<"4 Wyswietl stan oszczednosci"<<endl;
    cout<<"5 Wyjdz"<<endl;
    cin>>choice;
    forwardMenuOptions(wallet, choice, sv);
}

int main(int argc, const char * argv[]) {
    ifstream read;
    read.open("wallet.txt");
    ofstream write;
    auto *wallet = new Wallet<Asset>();
    if(read.peek() == ifstream::traits_type::eof()){
        cout<<"pusty plik portfela"<<endl;
    }
    else{
        wallet->load(read);
    }
    read.close();
    run = true;
    while(run) {
        displayMainMenu(*wallet, write);
    }
}
