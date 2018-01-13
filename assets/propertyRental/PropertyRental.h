//
// Created by Maciej Mościcki on 10.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_PROPERTYRENTAL_H
#define SAVINGS_CPP_PROJECT_PROPERTYRENTAL_H


#include "../Asset.h"

class PropertyRental : public Asset{
private:
    int rentValue, duration;
public:
    PropertyRental();

    PropertyRental(const string& name, int rentValue, int duration);

    void displayAssetInfo() override;

    double valueAfter(int months) override;

    PropertyRental* editAsset() override;

    void save(ofstream & save) override;

    int getRentValue() const;

    void setRentValue(int rentValue);

    int getDuration() const;

    void setDuration(int duration);

    ~PropertyRental() override;
};


#endif //SAVINGS_CPP_PROJECT_PROPERTYRENTAL_H
