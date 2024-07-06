// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t len = s.length();
        if(s.length()!=t.length())
            return false;
       unordered_map<char, size_t>map;
       for(size_t i=0;i<len;i++){
            map[s[i]]++;
            
       }

    }
};