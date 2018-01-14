//
// Created by Maciej Mościcki on 14.01.2018.
//

#include "WalletLoader.h"
#include "../../assets/crypto/Crypto.h"

Crypto* WalletLoader::loadCrypto(ifstream &ld) {
    string name;
    double baseValue, amount;
    ld>>name>>baseValue>>amount;
    auto *crypto = new Crypto(name, baseValue);
    crypto->setAmount(amount);
    return crypto;
}

Contract* WalletLoader::loadContract(ifstream &ld) {
    string name;
    int duration, gratification;
    double amount;
    ld>>name>>duration>>gratification>>amount;
    auto *contract = new Contract(name, duration, gratification);
    contract->setAmount(amount);
    return contract;
}

FundUnit* WalletLoader::loadFundUnit(ifstream &ld) {
    string name;
    double baseValue, amount;
    ld>>name>>baseValue>>amount;
    auto *fundUnit = new FundUnit(name, baseValue);
    fundUnit->setAmount(amount);
    return fundUnit;
}

FundUnitDividend* WalletLoader::loadFundUnitDividend(ifstream &ld) {
    string name;
    double baseValue, amount;
    int dividendFreq;
    ld>>name>>baseValue>>dividendFreq>>amount;
    auto *fundUnitDividend = new FundUnitDividend(name, baseValue, dividendFreq);
    fundUnitDividend->setAmount(amount);
    return fundUnitDividend;
}

Investment* WalletLoader::loadInvestment(ifstream &ld) {
    string name;
    double percentage, amount;
    int duration, moneyPutIn;
    ld>>name>>percentage>>duration>>moneyPutIn>>amount;
    auto *investment = new Investment(name, moneyPutIn, percentage, duration);
    investment->setAmount(amount);
    return investment;
}

PropertyRental* WalletLoader::loadPropertyRental(ifstream &ld) {
    string name;
    int rentValue, duration;
    double amount;
    ld>>name>>rentValue>>duration>>amount;
    auto *propertyRental = new PropertyRental(name, rentValue, duration);
    propertyRental->setAmount(amount);
    return propertyRental;
}
