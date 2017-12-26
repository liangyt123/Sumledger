#include "../header.h"
#include "transaction.h"
#include "block.h"
//构建默克尔树
class CMerkleTx{
    
    public:
        CMerkleTx(CTransaction t)
        {

        }

        int getDepthMainChain();
        int setMerkleBrach(CBlock);

    
    public:
        CMerkleTx *pprev = NULL;
        CMerkleTx *pnext = NULL;
        string hash;
        int index;
        string vMerkleBrach;

        
        


};

class CWalletTx{




};