#ifndef _INOUTPOINT_H
#define _INOUTPOINT_H
#include "../header.h"
class CInPoint{

        public:
            CInPoint(){
                hash = string("");
                n = -1;

            }

            CInPoint(string shash,unsigned int si){
                hash = shash;
                n = si;
            }
        
        public://操作符号重载
            friend bool operator>(CInPoint&a,CInPoint&b)
            {
                return atoi((a.hash).c_str())>atoi((b.hash).c_str());
            }

            friend bool operator<(CInPoint&a,CInPoint&b)
            {
                return atoi((a.hash).c_str())<atoi((b.hash).c_str());
            }

            friend bool operator==(CInPoint&a,CInPoint&b)
            {
                return atoi((a.hash).c_str())==atoi((b.hash).c_str());
            }

        public:string hash;
                unsigned int n;

    
};
/* code */

class COutPoint{

        public://操作符号重载
            friend bool operator<(COutPoint&a,COutPoint&b)
            {
                return atoi((a.hash).c_str())<atoi((b.hash).c_str());
            }

        public:string hash;
                unsigned int n;

};


#endif //_INOUTPOINT_H


