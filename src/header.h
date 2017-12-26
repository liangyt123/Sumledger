#include <iostream>
#include<string>
#include<string.h>
#include<map>
#include<vector>
#include<openssl/sha.h> 
#include<openssl/crypto.h> 
#include<openssl/bn.h>
#include<openssl/ec.h>
#include<exception>
#include<unistd.h>
using namespace std;
//宏定义
#define _CHECK_FAILED(rs) if(rs==-1) std::cout<<"the key:"<<#rs<<"is failed!";\
                                else std::cout<<"the key:"<<#rs<<"is true!"

