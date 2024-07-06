// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        double num=0,j=0,sign=1;
        double min=-2147483648,max=2147483647,temp;
        bool st=false;
         if(s[j]=='-'){
                sign=-1;
                j++;
              st=true;
            }else if(s[j]=='+'){
                j++;
              st=true;
         }
           while(s[j]=='+'||s[j]==' '||s[j]=='-'||s[j]=='0'){
                j++;
            if(s[j]=='-' &&!st){
                sign=-1;
                j++;
                st=true;
                }else if(s[j]=='+' &&!st){
                j++;
                st=true;
            }
           }
        for(int i=j;i<s.length();++i){
            if(isalpha(s[i])||s[j]=='-'||s[j]=='+')
                return 0;
            else if(s[i]==' ')
                 return num*sign;
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
                    j=7;
                    break;
                case '8':
                    j=8;
                    break;                 
                case '9':
                    j=9;
                    break;
                case '.':
                    j=-1;
                    break;
                default:
                    j=-2;
                
            }
             temp=(num*10)+j;
            if(temp >21474836478 &&sign==-1)
                return min;
            else if(temp>2147483647&&sign==1)
                    return max;
            if(j>=0){
                 num*=10;
                 num+=j;
            }else if(j==-1)
                return num;    
        }
        return num*sign;
    }
};