// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subs = "";
        size_t max = 0 , pos ,size;
        for(char c : s){
            pos = subs.find(c);
            if(pos != string::npos){
                size = subs.size();
                if(max < size)
                    max = size;

                subs.erase(0,pos+1);            
            }
            subs+=c;
        }

        return subs.size() > max ? subs.size() : max ;
    }
};