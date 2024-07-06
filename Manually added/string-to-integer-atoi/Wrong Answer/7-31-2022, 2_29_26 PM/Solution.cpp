// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    __int64_t myAtoi(string s) {
        __int64_t num=0 ;
        int strln =0;
        bool invert=false;
        bool found=false ,nonzero=false;
        string ss="";
        unsigned long tens=1;
        int len=s.length();
        for(int i=0;i<len;++i){
         if(isdigit(s[i])){
            if(s[i]!='0' || nonzero){
                nonzero=true;
                ss+=s[i];
            }
                strln++;
         }else if(s[i]=='-' && !found && strln==0){
             invert=true;
             found=true;
         }else if(s[i]=='+' && !found && strln==0){
             found=true;
         }else if (s[i]==' ' && !found && strln==0){
             continue;
         }else{
             break;
         }
        }
        if (ss.length() > 0){
             tens=pow(10, ss.length()-1);
        }
        cout<<ss.length()<<endl;
        for(int i=0;i < ss.length();++i){
           num+=(tens*(ss[i]-'0'));
           tens/=10;
        }
        if(num < 0)
            num=2147483647;
        
         if(invert){
            num=-1*num;
         }
  
        if (num > 2147483647)
            num = 2147483647;
        else if(num < -2147483648)
            num = -2147483648;
        
        return num;
    }
};