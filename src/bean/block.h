#include "../header.h"
class CBlockIndex{
    public:
        string hash;
        CBlockIndex* pprev;
        CBlockIndex* pnext;
        int height;
        

};