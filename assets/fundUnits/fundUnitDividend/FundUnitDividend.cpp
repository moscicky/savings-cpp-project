//
// Created by Maciej Mościcki on 12.01.2018.
//

#include "FundUnitDividend.h"

FundUnitDividend::FundUnitDividend(){
    int dividendFreq;
    cout<<"Podaj co ile miesiecy wyplacana jest dywidenda"<<endl;
    cin>>dividendFreq;
    setDividendFrequency(dividendFreq);
}



double FundUnitDividend::getDividendValue() {
    return dividendValue;
}

void FundUnitDividend::setDividendValue(double dividendValue) {
    FundUnitDividend::dividendValue = dividendValue;
}

int FundUnitDividend::getDividendFrequency() {
    return dividendFrequency;
}

void FundUnitDividend::setDividendFrequency(int dividendFrequency) {
    FundUnitDividend::dividendFrequency = dividendFrequency;
}

double FundUnitDividend::valueAfter(int months) {
    double rate = rand()%2;
    dividendValue = rand()%1000;
    if(dividendFrequency > months) {
        return getBaseValue() * getAmount() * rate;
    }
    else{
        double value = dividendValue + getBaseValue() * rate;
        for (int i = dividendFrequency; i < months; i+= dividendFrequency){
            value += dividendValue;
        }
        return value * getAmount();
    }
}

void FundUnitDividend::displayAssetInfo() {
    cout<<"Nazwa "<<getName()<<endl;
    cout<<"Wartosc poczatkowa "<<getBaseValue()<<endl;
    cout<<"Dywidenca co "<<getDividendFrequency()<<" miesiecy"<<endl;
}

void FundUnitDividend::save(ofstream &save) {
    save<<"FundUnitDividend"<<endl;
    save<<getName()<<" "<<getBaseValue()<<" "<<getDividendFrequency()<<" "<<getAmount()<<endl;
}
