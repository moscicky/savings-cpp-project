//
// Created by Maciej Mościcki on 11.01.2018.
//

#include "Forms.h"

Contract *Forms::displayNewContract() {
    string name;
    int duration, gratification;
    cout<<"Nowy kontrakt:"<<endl;
    cout<<"Podaj nazwe kontraktu: "<<endl;
    cin>>name;
    cout<<endl<<"Podaj dlugosc trwania kontraktu: "<<endl;
    cin>>duration;
    cout<<endl<<"Podaj sume pieniedzy uzyskana za wykonanie kontraktu"<<endl;
    cin>>gratification;

    auto *contract = new Contract(name, duration, gratification);
    return contract;
}

PropertyRental *Forms::displayNewPropertyRental() {
    string name;
    int duration, rentValue;
    cout<<"Nowy wynajem:"<<endl;
    cout<<"Podaj nazwe wynajmu: "<<endl;
    cin>>name;
    cout<<endl<<"Podaj wysokosc czynszu: "<<endl;
    cin>>rentValue;
    cout<<endl<<"Podaj w miesiacach dlugosc umowy najmu: "<<endl;
    cin>>duration;

    auto *propertyRental = new PropertyRental(name, rentValue, duration);
    return propertyRental;
}

Investment *Forms::displayNewInvestment() {
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

    auto *investment = new Investment(name, moneyPutIn, percentage, duration);
    return investment;
}

Crypto *Forms::displayNewBitcoin() {
    string name = "bitcoin";
    double baseValue;
    cout<<"Nowy bitcoin:"<<endl;
    cout<<endl<<"Podaj poczatkowa wartosc jednego bitcoina: "<<endl;
    cin>>baseValue;

    auto *bitcoin = new Crypto(name, baseValue);
    return bitcoin;
}
