#include <vector>


//txIn输入
class CTxIn{

    public: 
            int clear();
};


//txOut输出
class CTxOut{

    public:
            int clear();

};



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
        int nVersion;//交易的版本控制
        std::vector<CTxIn> vin;
        std::vector<CTxIn> vout;
        int nlockTime;

};