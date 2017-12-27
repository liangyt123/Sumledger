#include"../header.h"
 
 class CKey{
    public:
        CKey ()
        {

            pkey = EC_KEY_new_by_curve_name(NID_secp256k1);

        }
        //产生公钥 通过私钥
        CKey(const CKey &b)
        {
            pkey=EC_KEY_dup(b.pkey);
        }

    private:
        
        EC_KEY *pkey;


 };