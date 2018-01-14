//
// Created by Maciej Mościcki on 10.01.2018.
//
#include "Crypto.h"
using namespace std;


Crypto::Crypto(const string &name, double baseValue) : Asset(name) {
    Crypto::baseValue = baseValue;
}

Crypto::Crypto() {
    string name;
    double baseValue;
    cout<<"Kryptowaluta:"<<endl;
    cout<<"Podaj nazwe kryptowaluty:"<<endl;
    cin>>name;
    cout<<endl<<"Podaj poczatkowa wartosc jednej jednostki: "<<endl;
    cin>>baseValue;
    setName(name);
    setBaseValue(baseValue);
}

double Crypto::valueAfter(int months) {
    double rate = rand()%10/3;
    return baseValue * rate * getAmount();
}

void Crypto::displayAssetInfo() {
    cout<<"Nazwa "<<getName()<<endl;
    cout<<"Wartosc poczatkowa "<<getBaseValue()<<endl;
}

double Crypto::getBaseValue() const {
    return baseValue;
}

void Crypto::setBaseValue(double baseValue) {
    Crypto::baseValue = baseValue;
}

Crypto* Crypto::editAsset() {
    auto * crypto = new Crypto();
    crypto->setAmount(getAmount());
    return crypto;
}

void Crypto::save(ofstream &save) {
    save<<"Crypto"<<endl;
    save<<getName()<<" "<<getBaseValue()<<" "<<getAmount()<<endl;
}

Crypto::~Crypto() = default;


