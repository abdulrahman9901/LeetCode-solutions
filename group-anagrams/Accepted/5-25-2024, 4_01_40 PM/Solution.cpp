// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mapres;
        vector<vector<string>> res;
        for(auto str : strs){
            auto key = str;
            sort(key.begin(), key.end());
            mapres[key].push_back(str);
        }
        for(auto m:mapres){
            res.push_back(m.second);
        }
        return res;
    }
};