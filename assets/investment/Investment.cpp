//
// Created by Maciej Mościcki on 10.01.2018.
//

#include "Investment.h"

Investment::Investment(const string &name, double moneyPutIn, double percentage, int duration) : Asset(name) {
    Investment::percentage = percentage;
    Investment::duration = duration;
    Investment::moneyPutIn = moneyPutIn;
}

double Investment::valueAfter(int months) {
if(duration > months) {
    return moneyPutIn * getAmount();
}
else{
    double value = moneyPutIn + moneyPutIn * percentage/1000;
    for (int i = duration; i < months; i+= duration){
        value = value + value * percentage/100;
    }
    return value * getAmount();
    }
}


void Investment::displayAssetInfo() {
    cout<<"nazwa "<<getName()<<endl;
    cout<<"oprocentowanie "<<getPercentage()<<endl;
    cout<<"dlugosc trwania "<<getDuration()<<endl;
    cout<<"wlozone pieniadze "<<getMoneyPutIn()<<endl;
}


int Investment::getDuration() {
    return duration;
}

void Investment::setDuration(int duration) {
    Investment::duration = duration;
}

double Investment::getPercentage() {
    return percentage;
}

void Investment::setPercentage(double percentage) {
    Investment::percentage = percentage;
}

double Investment::getMoneyPutIn() const {
    return moneyPutIn;
}

void Investment::setMoneyPutIn(double moneyPutIn) {
    Investment::moneyPutIn = moneyPutIn;
}

Investment::Investment() {
    string name;
    int duration;
    double percentage, moneyPutIn;
    cout<<"Lokata:"<<endl;
    cout<<"Podaj nazwe lokaty: "<<endl;
    cin>>name;
    cout<<endl<<"Podaj oprocentowanie lokaty: "<<endl;
    cin>>percentage;
    cout<<endl<<"Podaj w miesiach okres po ktorym kumuluja sie odsetki"<<endl;
    cin>>duration;
    cout<<endl<<"Podaj wlozona sume pieniedzy"<<endl;
    cin>>moneyPutIn;

    setName(name);
    setDuration(duration);
    setPercentage(percentage);
    setMoneyPutIn(moneyPutIn);
}

Investment* Investment::editAsset() {
    auto * investment = new Investment;
    investment->setAmount(getAmount());
    return investment;
}

void Investment::save(ofstream & save) {
    save<<"Investment"<<endl;
    save<<getName()<<" "<<getPercentage()<<" "<<getDuration()<<" "<<getMoneyPutIn()<<" "<<getAmount()<<endl;
}


Investment::~Investment() = default;
