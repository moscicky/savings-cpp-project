//
// Created by Maciej Mościcki on 12.01.2018.
//

#include "FundUnit.h"

FundUnit::FundUnit() {
    string name;
    double baseValue;
    cout<<"Jednostka funduszu inwestcyjnego:"<<endl;
    cout<<"Podaj nazwe funduszu:"<<endl;
    cin>>name;
    cout<<endl<<"Podaj poczatkowa wartosc jednej jednostki: "<<endl;
    cin>>baseValue;
    setName(name);
    setBaseValue(baseValue);
}

FundUnit::FundUnit(const string &name, double baseValue) : Asset(name) {
    FundUnit::baseValue = baseValue;
}

double FundUnit::valueAfter(int months) {
    double rate = rand()%5;
    return baseValue * rate * getAmount();
}

void FundUnit::displayAssetInfo() {
    cout<<"Nazwa "<<getName()<<endl;
    cout<<"Wartosc poczatkowa jednostki "<<getBaseValue()<<endl;
}

FundUnit *FundUnit::editAsset() {
    auto* fundUnit = new FundUnit();
    fundUnit->setAmount(getAmount());
    return fundUnit;
}

double FundUnit::getBaseValue(){
    return baseValue;
}

FundUnit::~FundUnit() = default;

void FundUnit::setBaseValue(double baseValue) {
 FundUnit::baseValue = baseValue;
}

void FundUnit::save(ofstream &save) {
    save<<"FundUnit"<<endl;
    save<<getName()<<" "<<getBaseValue()<<" "<<getAmount()<<endl;
}
