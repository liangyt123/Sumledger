#include "init.h"
    

string 
appInt::getFromMap(map<string,string> &pmap,string key){

    if(pmap.count(key))
    {
         return  pmap[key];
    };
    return string("");
}


void 
appInt::init(int argc,char * argv[]){

    //死循环  每隔一秒中进行一次刷新
    // while(1)
    // {
    //     sleep(1);
    // }
    //对参数进行解析
     map<string,string> pmap = parseParameters(argc,argv);
    //有一个加节点的参数
     getFromMap(pmap,"/add");
     getFromMap(pmap,"/datadir");

     //各种预备的处理
     //提供接口
     //加载数据 这些数据还是依赖着db，wallet类 应该放到service文件夹进行操作中
    //  _CHECK_FAILED(loadAddress());
    //  _CHECK_FAILED(loadBlockIndex());
    //  _CHECK_FAILED(loadWallet());
     
}

map<string,string> 
appInt::parseParameters(int argc,char * argv[]){
    map<string,string> pmap;
    //对于每个-key=value进行处理
    for(int i = 0;i<argc;i++)
    {
        char psz[10000];
        strcpy(psz,argv[i]);
        //找字符串首次出现“=”的位置
        char * val;
        if(strchr(psz,'='))
        {
            val = strchr(psz,'=');
            *val++='\0';
        };
        //-key'\0'=value
       // strlwr(psz);
        if(psz[0]=='-')
            psz[0]='/';
        //此时tmp为一个输入的字符串的value部分
        //i到val为key
        pmap[psz]=val;
    }
    return pmap;
};
