// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t len = s.length();
        if(s.length()!=t.length())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
       unordered_map<char, int>map;
       for(size_t i=0;i<len;i++){
            map[s[i]]++;
            map[t[i]]--;
            if(map[t[i]]!=0) 
                return false;   
       }
       return true;
    }
};