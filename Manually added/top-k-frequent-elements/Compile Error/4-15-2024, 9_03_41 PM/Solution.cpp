// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
bool cmp(pair<int,size_t>& a, 
        pair<int,size_t>& b) 
{ 
    return a.second < b.second; 
} 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,size_t>map;
        
        for(auto num:nums){
            map[num]++;
        }
        sort(map.begin(),map.end(),cmp);
        for(auto ele:map){

        }
    }
};