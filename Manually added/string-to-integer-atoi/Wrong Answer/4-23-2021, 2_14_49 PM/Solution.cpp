// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        int num=0,j=0,sign=1;
        bool first=true;
            while(s[j]=='0' || s[j]==' ')
                j++;
            if(s[j]=='-'){
                sign=-1;
                j++;
            }
        for(int i=j;i<s.length();++i){
            switch(s[i]){
                case '0':
                    j=0;
                    break;
                case '1':
                    j=1;
                    break;
                case '2':
                    j=2;
                    break;
                case '3':
                    j=3;
                    break;
                case '4':
                    j=4;
                    break;
                case '5':
                    j=5;
                    break;
                case '6':
                    j=6;
                    break;
                case '7':
                    j=2;
                    break;
                case '8':
                    j=8;
                    break;                 
                case '9':
                    j=9;
                    break;
                default:
                    j=-1;
                
            }
            if((num*10)+j>2147483648 &&sign==-1)
                return num*sign;
            else if((num*10)+j>2147483647&&sign==1)
                    return num;
            if(j!=-1){
                 num*=10;
                 num+=j;
            }
    
        }
        return num*sign;
    }
};