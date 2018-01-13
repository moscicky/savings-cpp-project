//
// Created by Maciej Mościcki on 10.01.2018.
//

#include <fstream>
#include "PropertyRental.h"
PropertyRental::PropertyRental(const string &name, int rentValue, int duration) : Asset(name){
    PropertyRental::rentValue = rentValue;
    PropertyRental::duration = duration;
}

void PropertyRental::displayAssetInfo() {
    cout<<"nazwa "<<getName()<<endl;
    cout<<"wysokosc czynszu "<<getRentValue()<<endl;
    cout<<"dlugosc trwania najmu "<<getDuration()<<endl;
}

double PropertyRental::valueAfter(int months) {
    return months > duration ? duration * rentValue * getAmount() : months * rentValue * getAmount();
}

PropertyRental::PropertyRental() {
    string name;
    int duration, rentValue;
    cout<<"Wynajem:"<<endl;
    cout<<"Podaj nazwe wynajmu: "<<endl;
    cin>>name;
    cout<<endl<<"Podaj wysokosc czynszu: "<<endl;
    cin>>rentValue;
    cout<<endl<<"Podaj w miesiacach dlugosc umowy najmu: "<<endl;
    cin>>duration;

    setName(name);
    setDuration(duration);
    setRentValue(rentValue);
}

int PropertyRental::getRentValue() const {
    return rentValue;
}

void PropertyRental::setRentValue(int rentValue) {
    PropertyRental::rentValue = rentValue;
}

int PropertyRental::getDuration() const {
    return duration;
}

void PropertyRental::setDuration(int duration) {
    PropertyRental::duration = duration;
}

PropertyRental *PropertyRental::editAsset() {
    auto * propertyRental = new PropertyRental();
    propertyRental->setAmount(getAmount());
    return propertyRental;
}

void PropertyRental::save(ofstream & save) {
    save<<"PropertyRental"<<endl;
    save<<getName()<<" "<<getRentValue()<<" "<<getDuration()<<" "<<getAmount()<<endl;
}

PropertyRental::~PropertyRental() = default;