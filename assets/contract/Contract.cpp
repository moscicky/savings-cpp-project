//
// Created by Maciej Mościcki on 10.01.2018.
//

#include "Contract.h"

Contract::Contract(const string &name, int duration, int gratification) : Asset(name) {
    Contract::duration = duration;
    Contract::gratification = gratification;
}

void Contract::displayAssetInfo() {
    cout<<"nazwa "<<getName()<<endl;
    cout<<"dlugosc trwania kontraktu "<<getDuration()<<endl;
    cout<<"wynagrodzenie "<<getGratification()<<endl;
}


double Contract::valueAfter(int months) {
    if(months < duration){
        return 0;
    }
    else{
        return gratification * getAmount();
    }
}

int Contract::getDuration() {
    return duration;
}

void Contract::setDuration(int duration) {
    Contract::duration = duration;
}

int Contract::getGratification() {
    return gratification;
}

void Contract::setGratification(int gratification) {
    Contract::gratification = gratification;
}

Contract::Contract() {
    string name;
    int duration, gratification;
    cout<<"Kontrakt:"<<endl;
    cout<<"Podaj nazwe kontraktu: "<<endl;
    cin>>name;
    cout<<endl<<"Podaj dlugosc trwania kontraktu: "<<endl;
    cin>>duration;
    cout<<endl<<"Podaj sume pieniedzy uzyskana za wykonanie kontraktu"<<endl;
    cin>>gratification;
    setName(name);
    setDuration(duration);
    setGratification(gratification);
}

Contract* Contract::editAsset() {
    auto * contract = new Contract();
    contract->setAmount(getAmount());
    return contract;
}

void Contract::save(ofstream &save) {
    save<<"Contract"<<endl;
    save<<getName()<<" "<<getDuration()<<" "<<getGratification()<<" "<<getAmount()<<endl;
}

Contract::~Contract() = default;
