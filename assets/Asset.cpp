//
// Created by Maciej Mościcki on 10.01.2018.
//
#include "Asset.h"


string Asset::getName(){
    return name;
}

void Asset::setName(const string& name) {
    Asset::name = name;
}

Asset::Asset(const string& name) {
    Asset::name = name;
}

Asset::~Asset() = default;

double Asset::getAmount() const {
    return amount;
}

void Asset::setAmount(double amount) {
    Asset::amount = amount;
}

Asset::Asset() = default;


Asset& Asset::operator-=(double value) {
    this->setAmount(this->getAmount() - value);
    return *this;
}

Asset& Asset::operator+=(double value) {
    this->setAmount(this->getAmount() + value);
    return *this;
}