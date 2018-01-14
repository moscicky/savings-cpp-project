//
// Created by Maciej Mościcki on 10.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_BITCOIN_H
#define SAVINGS_CPP_PROJECT_BITCOIN_H

#include "../Asset.h"
using namespace std;

class Crypto : public Asset{
private:
    double baseValue;
public:
    Crypto();

    Crypto(const string& name, double baseValue);

    double valueAfter(int months) override;

    void displayAssetInfo() override;

    Crypto* editAsset() override;

    double getBaseValue() const;

    ~Crypto() override;

    void setBaseValue(double baseValue);

    void save(ofstream &save) override;
};


#endif //SAVINGS_CPP_PROJECT_BITCOIN_H
