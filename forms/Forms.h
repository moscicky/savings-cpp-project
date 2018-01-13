//
// Created by Maciej Mościcki on 11.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_FORMS_H
#define SAVINGS_CPP_PROJECT_FORMS_H


#include "../assets/contract/Contract.h"
#include "../assets/propertyRental/PropertyRental.h"
#include "../assets/investment/Investment.h"
#include "../assets/bitcoin/Crypto.h"

class Forms {
public:
    Contract* displayNewContract();
    PropertyRental* displayNewPropertyRental();
    Investment* displayNewInvestment();
    Crypto* displayNewBitcoin();
};


#endif //SAVINGS_CPP_PROJECT_FORMS_H
