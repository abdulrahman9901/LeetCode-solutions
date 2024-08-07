class Solution {
public:
    string longestPalindrome(string s) {
        int r , l ;
        int reslen = 0;
        string res;
        int len = s.size();
        for(int i = 0 ;i <len;++i){    
            r = l = i;          
           while(r < len && l >= 0 && s[l]==s[r]){
                if(r-l+1 >= reslen){
                    reslen = r-l+1 ;
                    res = s.substr(l,reslen);
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;          
           while(r < len && l >= 0 && s[l]==s[r]){
                if(r-l+1 >= reslen){
                    reslen = r-l+1 ;
                    res = s.substr(l,reslen);
                }
                l--;
                r++;
            }
        }    
            return res;
    }
};