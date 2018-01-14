//
// Created by Maciej Mościcki on 12.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_FUNDUNITDIVIDEND_H
#define SAVINGS_CPP_PROJECT_FUNDUNITDIVIDEND_H


#include "../FundUnit.h"

class FundUnitDividend : public FundUnit{
public:
    FundUnitDividend();
    FundUnitDividend(string &name, double baseValue, int dividendFreq);
private:
    double dividendValue;
    int dividendFrequency;
public:
    double getDividendValue();

    void setDividendValue(double dividendValue);

    int getDividendFrequency();

    double valueAfter(int months) override;

    void displayAssetInfo() override;

    void save(ofstream & save) override;

    void setDividendFrequency(int dividendFrequency);
};


#endif //SAVINGS_CPP_PROJECT_FUNDUNITDIVIDEND_H
