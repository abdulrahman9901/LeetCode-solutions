// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        double num=0,j=0,sign=1;
        double temp=0;
        bool first=true;
            while(s[j]=='0' || s[j]==' ')
                j++;
            if(s[j]=='-'){
                sign=-1;
                j++;
            }
        for(int i=j;i<s.length();++i){
            if(isalpha(s[i]))
                return num;
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
             temp=(num*10)+j;
            if(temp >21474836478 &&sign==-1)
                return 21474836478*sign;
            else if(temp>2147483647&&sign==1)
                    return 2147483647;
            if(j!=-1){
                 num*=10;
                 num+=j;
            }
    
        }
        return num*sign;
    }
};