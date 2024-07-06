// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int found = -1;
        for(auto c:s){
            found=t.find(c,found+1);
            if(found == std::string::npos)
                return false;
        }

        return true;
    }
};