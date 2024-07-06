// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    __int64_t myAtoi(string s) {
        __int64_t num=0 ;
        int strln =0;
        bool invert=false;
        bool found=false;
        string ss="";
        int len=s.length();
        for(int i=0;i<len;++i){
         if(isdigit(s[i])){
            strln++;
            ss+=s[i];
         }else if(s[i]=='-' && !found){
             invert=true;
         }else if(s[i]==' ' || (s[i]=='+' && !invert)){
             continue;
         }else{
             break;
         }
        }
        unsigned long tens=pow(10, strln-1);
        for(int i=0;i<strln;++i){
           num+=(tens*(ss[i]-'0'));
           tens/=10;
        }
         if(invert)
            num=-1*num;
        else
            num=num;
        
        if (num > 2147483647)
            num = 2147483647;
        else if(num < -2147483648)
            num = -2147483648;
        
        return num;
    }
};