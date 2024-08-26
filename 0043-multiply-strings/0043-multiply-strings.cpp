class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        reverse(num1.begin(), num1.end()); 
        reverse(num2.begin(), num2.end()); 
        vector<int> res(len1+len2,0);
        string resStr="";
        for(int i = 0 ; i < len1 ;++i){
            for(int j = 0 ; j < len2 ;++j){
                int digit = (num1[i]-'0') * (num2[j]-'0');
                res[i+j]+=digit;
                res[i+j+1]+=res[i+j]/10;
                res[i+j]=res[i+j]%10;
                }  
            }
            for(auto it =res.rbegin();it!=res.rend();++it)
                if (!(resStr.empty() && *it == 0)) { 
                    resStr += (*it + '0');
                }
        return resStr.empty() ? "0" : resStr;    
    }
};