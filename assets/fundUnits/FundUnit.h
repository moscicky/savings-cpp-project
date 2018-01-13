//
// Created by Maciej Mościcki on 12.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_FUNDUNIT_H
#define SAVINGS_CPP_PROJECT_FUNDUNIT_H


#include "../Asset.h"

using namespace std;

class FundUnit : public Asset{
private:
    double baseValue;
public:
    FundUnit();

    FundUnit(const string& name, double baseValue);

    double valueAfter(int months) override;

    void displayAssetInfo() override;

    FundUnit* editAsset() override;

    double getBaseValue();

    ~FundUnit() override;

    void setBaseValue(double baseValue);

    void save(ofstream &save) override;
};


#endif //SAVINGS_CPP_PROJECT_FUNDUNIT_H
