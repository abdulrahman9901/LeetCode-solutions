class Solution {
public:
    int countSubstrings(string s) {
        int r , l ;
        int count = 0;
        int len = s.size();
        for(int i = 0 ;i <len;++i){    
            r = l = i;          
           while(r < len && l >= 0 && s[l]==s[r]){
                count++;
                l--;
                r++;
            }

            l = i;
            r = i+1;          
           while(r < len && l >= 0 && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }  
        return count; 
    }
};