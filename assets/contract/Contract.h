//
// Created by Maciej Mościcki on 10.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_CONTRACT_H
#define SAVINGS_CPP_PROJECT_CONTRACT_H


#include "../Asset.h"

class Contract : public Asset {
private:
    int duration, gratification;

public:
    Contract();

    Contract(const string& name, int duration, int gratification);

    void displayAssetInfo() override;

    double valueAfter(int months) override;

    Contract* editAsset() override;

    int getDuration();

    void setDuration(int duration);

    void save(ofstream &save) override;

    int getGratification();

    void setGratification(int gratification);

    ~Contract() override;
};


#endif //SAVINGS_CPP_PROJECT_CONTRACT_H
