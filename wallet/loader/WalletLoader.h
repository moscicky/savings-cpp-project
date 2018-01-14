//
// Created by Maciej Mościcki on 14.01.2018.
//

#ifndef SAVINGS_CPP_PROJECT_WALLETLOADER_H
#define SAVINGS_CPP_PROJECT_WALLETLOADER_H

using namespace std;
#include <fstream>
#include "../../assets/crypto/Crypto.h"
#include "../../assets/contract/Contract.h"
#include "../../assets/fundUnits/FundUnit.h"
#include "../../assets/fundUnits/fundUnitDividend/FundUnitDividend.h"
#include "../../assets/investment/Investment.h"
#include "../../assets/propertyRental/PropertyRental.h"

class WalletLoader {
public:
    Crypto* loadCrypto(ifstream & ld);

    Contract* loadContract(ifstream & ld);

    FundUnit* loadFundUnit(ifstream & ld);

    FundUnitDividend* loadFundUnitDividend(ifstream & ld);

    Investment* loadInvestment(ifstream & ld);

    PropertyRental* loadPropertyRental(ifstream & ld);
};


#endif //SAVINGS_CPP_PROJECT_WALLETLOADER_H
