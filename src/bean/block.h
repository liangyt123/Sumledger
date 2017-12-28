#include "../header.h"
#include "./transaction.h"
//区块索引
class CBlockIndex{
    public:
        string hash;
        CBlockIndex* pprev;
        CBlockIndex* pnext;
        int height;
};

//区块类
class CBlock{

    public:
        int nVersion;
        std::string hashPrevBlock;
        std::string hashMerkleRoot;
        int nTime;
        int nNonce;

        std::vector<CTransaction> vtc;

};

//