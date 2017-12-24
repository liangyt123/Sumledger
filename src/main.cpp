
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "tool/base58.h"
int main(int argc, char *argv[])
{
    
    std::cout<<"hello"<<std::endl;
     std::string tmp = "hello";

    //std::cout<<CTOOL::getInstance()->decodeBase58(tmp)<<std::endl;
    std::cout<<CTOOL::getInstance()->encodeBase58Check(tmp)<<std::endl;

  //  std::cout<<CTOOL::getInstance()->encodeBase58(tmp)<<std::endl;
  
 
    return 0;
}