//Copyright(c) 2017 liangyuanting
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.
#ifndef  BASE58_H/*define*/
#define  BASE58_H/*define*/
#include "../header.h"
static  std::string pszBase58 = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

class Cbase58{
        
        public:
                static Cbase58 *getInstance();
                //这里涉及怎么把一个字符串转为数字，将数字编码再转为字符串//加密后的字符串长度是原来的4/3倍
                    
                //将输入的Inhash一次后再进行返回一个解码
                inline std::string 
                encodeBase58Check( std::string &str)
                {
                    const std::string tmp = makeToSHA256(str.c_str());
                    std::cout<<tmp<<std::endl;
                    return encodeBase58(tmp);
                }


                inline const std::string 
                makeToSHA256( std::string input)
                {

                    unsigned char md[SHA256_DIGEST_LENGTH] = {0};  
                    SHA256((const unsigned char*)input.c_str(),input.length(),md);
                    int i = 0;  
                    char buf[65] = {0};  
                    char tmp[3] = {0};  
                    for(i = 0; i < 32; i++ )  
                    {  
                        sprintf(tmp,"%02X", md[i]);  
                        //一个char两个字节 两个16位
                        strcat(buf, tmp);  
                    }  
                    return std::string(buf);
                }

                inline std::string 
                decodeBase58(const std::string &str)
                {
                    std::string tmp = std::string(str);
                    const char *psz = str.c_str();
                    std::string result = std::string("");
                    BIGNUM *rem = BN_new();
                    BIGNUM *bn0 = BN_new();
                    BIGNUM *mul = BN_new();
                    BIGNUM *bn = BN_new();
                    BIGNUM *bn58 = BN_new();
                    BN_CTX *pctx = BN_CTX_new();
                    BN_CTX_init(pctx);
                    BN_init(bn);
                    BN_init(rem);
                    BN_init(bn0);
                    BN_init(bn58);
                    BN_dec2bn(&bn58,"58");
                    BN_dec2bn(&bn0,"0");
                    BN_hex2bn(&bn,str.c_str());
                    int cmp = BN_cmp((const BIGNUM*)bn,(const BIGNUM*)bn0);
                    for(const char* p = psz;*p;p++)
                    {
                        //找到当前的字符的
                        const char *p1 = strchr(pszBase58.c_str(),*p);
                        BN_set_word(mul,(p1-pszBase58.c_str()));
                        BN_mul(bn,bn,bn58,pctx);
                        BN_add(bn,bn,mul);

                    }
                    
                    BN_free(bn);
                    BN_free(mul);
                    BN_free(bn0);
                    BN_free(bn58);
                
                    OPENSSL_free(pctx);
                    
                    return tmp;
                }  

                //8比特字节码转为6比特的数据
                inline std::string
                encodeBase58(const std::string &str)
                {
                    std::string result = std::string("");
                    std::string tmp = std::string("");
                    const char *tp = str.c_str();

                    BIGNUM *rem = BN_new();
                    BIGNUM *bn0 = BN_new();
                    BIGNUM *dv = BN_new();
                    BIGNUM *bn = BN_new();
                    BIGNUM *bn58 = BN_new();
                    BN_CTX *pctx = BN_CTX_new();
                    BN_CTX_init(pctx);
                    BN_init(bn);
                    BN_init(rem);
                    BN_init(bn0);
                    BN_init(bn58);
                    BN_dec2bn(&bn58,"58");
                    BN_dec2bn(&bn0,"0");
                    BN_hex2bn(&bn,str.c_str());
                    int cmp = BN_cmp((const BIGNUM*)bn,(const BIGNUM*)bn0);
                    while ( cmp>0)
                    {
                        std::cout<<cmp<<std::endl;
                        if (!BN_div(dv, rem, bn, bn58, pctx))
                            throw std::bad_exception();
                        BN_copy(bn,dv);
                        //bn = dv;
                        unsigned int c = BN_get_word(rem);
                        std::cout<<"c:"<<c<<std::endl;
                        result += pszBase58[c];
                        cmp = BN_cmp((const BIGNUM*)bn,(const BIGNUM*)bn0);

                    }

                    //std::cout<<"makeresult"<<result<<std::endl;
                   
                    
                    BN_free(bn);
                    BN_free(dv);
                    BN_free(bn0);
                    BN_free(bn58);
                    BN_free(rem);
                    OPENSSL_free(pctx);
                    
                    return result;
                }

                inline std::string
                stringto6bin(int in)
                {
                    std::string val= std::string("");
                    
                    int i = 0;
                    for(;in!=0;i++,in/=2)
                    {
                        //std::cout<<in<<std::endl;
                        val.append(std::to_string(in%2));
                    }
                    if(val.size()%6 == 0)
                    {
                    
                        return val;
                    }
                    //std::cout<<val<<std::endl;
                    int count =6 -val.size()%6;
                    
                    std::string t2 = std::string(count,'0');
                    val = t2.append(val);
                    
                    return val;
                }
        private:static CTOOL* instance ;

};

#endif //_BASE58_H/*define*/



