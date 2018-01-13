//
// Created by Maciej Mościcki on 10.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_INVESTMENT_H
#define SAVINGS_CPP_PROJECT_INVESTMENT_H


#include "../Asset.h"

class Investment : public Asset{
private:
    int duration;
    double percentage, moneyPutIn;
public:
    Investment();

    Investment(const string &name, double moneyPutIn, double percentage, int duration);

    double valueAfter(int months) override;

    void displayAssetInfo() override;

    Investment* editAsset() override;

    int getDuration();

    void setDuration(int duration);

    double getPercentage();

    void setPercentage(double percentage);

    double getMoneyPutIn() const;

    void setMoneyPutIn(double moneyPutIn);

    void save(ofstream & save) override;

    ~Investment() override;
};


#endif //SAVINGS_CPP_PROJECT_INVESTMENT_H
