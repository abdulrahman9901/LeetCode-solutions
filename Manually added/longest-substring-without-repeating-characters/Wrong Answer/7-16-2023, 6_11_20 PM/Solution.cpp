// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs = "";
        int max = 1;
        for(char c : s){
            size_t pos = subs.find(c);
            if(pos != string::npos){
                if(max < subs.size())
                    max = subs.size();

                subs.erase(0,pos+1);            
            }
            subs+=c;
        }
        return max;
    }
};