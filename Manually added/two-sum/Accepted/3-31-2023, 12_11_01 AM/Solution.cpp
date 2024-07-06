// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0 , complement;
        size_t len = nums.size() ;
        unordered_map<int, int> map;
        for(i = 0 ; i <len;i++){
            complement = target - nums[i];
            if(map.find(complement) != map.end()){
                return {map[complement],i};
            }else 
                map[nums[i]]=i;
        }
        return {-1,-1};
    }
};