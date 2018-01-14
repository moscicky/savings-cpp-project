//
// Created by Maciej Mościcki on 10.01.2018.
//
#include <iostream>
#include <vector>
#include "../assets/Asset.h"
#include "loader/WalletLoader.h"

using namespace std;

template <class T>
class Wallet{
private:
    vector<T*> assets;
public:
    Wallet() = default;
    void displayAllAssets(){
        cout<<endl<<"----- STAN PORTFELA -----"<<endl;
        for(int i = 0; i < assets.size(); i++){
                cout<<i<<" "<<assets[i]->getName()<<" "<<"posiadana ilosc "<<assets[i]->getAmount()<<endl;
        }
        cout<<endl<<"-----------------------"<<endl;
    }

    void editWholeAsset(int index){
        cout<<"Stare wartości pól aktywa: "<<endl;
        assets[index]->displayAssetInfo();
        Asset * ptr  = assets[index];
        cout<<"Podaj nowe: ";
        assets[index] = assets[index]->editAsset();
        delete ptr;
    }

    void editAmount(int index){
        int choice;
        double amount;
        cout<<"Chcesz zmniejszyc czy zwiekszyc ilosc aktywa? Obecnia wynosi ona "<<assets[index]->getAmount()<<endl;
        cout<<"1 Zwiekszyc"<<endl;
        cout<<"2 Zmniejszyc"<<endl;
        cin>>choice;
        cout<<"O ile? Pamietaj zeby zachowac wartosc dodatnia"<<endl;
        cin>>amount;
        if(choice == 1){
            *assets[index]+=amount;
        }
        else{
            *assets[index]-=amount;
        }
    }

    void displayValueAfter(int months){
        double value = 0;
        for(int i = 0; i < assets.size(); i++){
            value += assets[i]->valueAfter(months);
        }
        cout<<endl<<"Wartosc portfela po "<<months<<" miesiacach to "<<value<<endl<<endl;
    }

    void addAsset(T* t){
        int amount;
        cout<<"Podaj ilosc aktywa "<<endl;
        cin>>amount;
        t->setAmount(amount);
        assets.push_back(t);
    }

    void loadAsset(T *t){
        assets.push_back(t);
    }

    void save(ofstream & sv){
        cout<<"zapisuje"<<endl;
        sv.open("wallet.txt", ios::trunc | ios::in | ios::out);
        for(int i = 0; i < assets.size(); i++){
            assets[i]->save(sv);
        }
        sv.close();
    }

    void load(ifstream & ld){
        WalletLoader walletLoader;
        string assetName;
        while(!ld.eof()){
            ld>>assetName;
            if(assetName == "Contract"){
                loadAsset(walletLoader.loadContract(ld));
            }
            else if(assetName == "Crypto"){
                loadAsset(walletLoader.loadCrypto(ld));
            }
            else if(assetName == "FundUnit"){
                loadAsset(walletLoader.loadFundUnit(ld));
            }
            else if(assetName == "FundUnitDividend"){
                loadAsset(walletLoader.loadFundUnitDividend(ld));
            }
            else if(assetName == "Investment"){
                loadAsset(walletLoader.loadInvestment(ld));
            }
            else if(assetName == "PropertyRental"){
                loadAsset(walletLoader.loadPropertyRental(ld));
            }
        }
        removeAsset(assets.size() - 1);
    }

    void removeAsset(int index){
        assets.erase(assets.begin() + index);
    }
};
