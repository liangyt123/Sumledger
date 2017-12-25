#ifndef _TRANSACTION_H
#define _TRANSACTION_H
/* code */

#include "../header.h"
#include "txInOut.h"
class CTransaction{
    
    public:
        CTransaction()
        {
            nVersion = 1;
            nlockTime = 0;
            vin.clear();
            vout.clear();
            
        }

    public:
        bool IsNull(){
            return (vin.empty()&&vout.empty());
        }


    public:
        int nVersion;//交易的版本控制
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;
        int nlockTime;

};
#endif //_TRANSACTION_H

