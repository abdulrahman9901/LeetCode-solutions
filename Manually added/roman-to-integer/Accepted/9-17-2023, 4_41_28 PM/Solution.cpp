// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        size_t lastVal=0,currVal=0,total=0;
        for(size_t i =0 ; i<s.length();++i){
            switch(s[i]){
                case 'I':
                currVal = 1;
                break;
                 case 'V':
                currVal = 5;
                break;
                 case 'X':
                 currVal = 10;
                break;
                case 'L':
                currVal = 50;
                break;
                 case 'C':
                 currVal = 100;
                break;
                 case 'D':
                 currVal = 500;
                break;
                 case 'M':
                 currVal = 1000;
                break;
            }
        if(lastVal < currVal){
            total += currVal - 2 * lastVal ;
        }else{
            total += currVal ;
        } 
        lastVal = currVal ;

        }
    return total;
    }
};