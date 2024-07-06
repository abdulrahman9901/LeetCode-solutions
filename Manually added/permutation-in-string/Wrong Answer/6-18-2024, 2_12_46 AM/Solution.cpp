// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0,r=0;
        while(r < s2.length()){
           if(s1.find(s2[r]) == string::npos){
                r++;
                l=r;
            }else{
                if(r-l+1 == s1.length()){
                    return true;
                }
                r++;
            }

        }
        return false;
    }
};