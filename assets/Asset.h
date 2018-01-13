//
// Created by Maciej Mościcki on 10.01.2018.
//
#include<iostream>
#include<fstream>
using namespace std;
#ifndef SAVINGS_CPP_PROJECT_ASSET_H
#define SAVINGS_CPP_PROJECT_ASSET_H


class Asset{
private:
    string name;
    double amount;
public:
    double getAmount() const;

    void setAmount(double amount);

public:
    explicit Asset(const string& name);

    Asset();

    virtual double valueAfter(int months) = 0;

    virtual void displayAssetInfo() = 0;

    virtual Asset* editAsset() = 0;

    virtual void save(ofstream & save) = 0;

    virtual ~Asset();

    string getName();

    void setName(const string &name);

    Asset& operator+=(double value);
    Asset& operator-=(double value);
};




#endif //SAVINGS_CPP_PROJECT_ASSET_H
