// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        for(auto c : s){
            if(t.find(c) == string::npos)
                return false;
        }
        return true;
    }
};