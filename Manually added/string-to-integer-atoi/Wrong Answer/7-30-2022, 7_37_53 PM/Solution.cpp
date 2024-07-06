// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int num=0 ,strln =0;
        bool invert=false;
        int len=s.length();
        for(int i=0;i<len;++i){
         if(s[i]=='-'){
             invert=true;
         }
         if(isdigit(s[i])){
            strln++;
         }
        }
        int tens=pow(10, strln-1);
        for(int i=0;i<len;++i){
         if(isdigit(s[i])){
           num+=(tens*(s[i]-'0'));
           tens/=10;
         }else if(s[i]==' '){
             continue;
         }
            else{
                break;
            }
        }
        if(invert)
            return -1*num;
        else
            return num;
    }
};