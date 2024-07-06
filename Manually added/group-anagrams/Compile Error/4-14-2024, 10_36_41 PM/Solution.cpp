// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        for(auto str in strs){
            sort(str.begin(),str.end());
        }

    }
};