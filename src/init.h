#ifndef _INIT_H
#define _INIT_H
/* code */
#include"header.h"
#include "./bean/transaction.h"
#include "./bean/block.h"
#include "tool/base58.h"
//全局变量

using namespace std;
//参数不会很多，放入栈中，所以用返回模式，返回一个map的拷贝 这里不用全局变量
// map<string,string> mapArgs;

//这里都是区块链程序用到的所有的一个
class appInt{

    public:
        void init(int argc,char * argv[]);
        map<std::string,std::string> parseParameters(int argc,char * argv[]);
        
        int loadAddress();
        int loadBlockIndex();
        int loadWallet();

    public:
        string getFromMap(map<string,string> &pmap,string key);

    private:
        //相关参数
        string addval;
        string datadir;
        map<string,CTransaction> mapTransactions;
        map<string,CBlockIndex> mapBlockIndex;
        map<string,bool>vWalletUpdated;
        




};


#endif //_INIT_H

