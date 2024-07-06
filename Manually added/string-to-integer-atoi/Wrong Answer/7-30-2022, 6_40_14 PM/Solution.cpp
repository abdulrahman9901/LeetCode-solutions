// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int num=0 ,strln =0;
        int len=s.length();
        for(int i=0;i<len;++i){
         if(isdigit(s[i])){
            strln++;
         }
        }
        int tens=pow(10, strln-1);
        for(int i=0;i<len;++i){
         if(isdigit(s[i])){
           num+=(tens*(s[i]-'0'));
           tens/=10;
         }
        }
        return num;
    }
};