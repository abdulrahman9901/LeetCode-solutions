// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result{-1,-1};
        for(auto i = 0 ; i <nums.size();i++){
            for(auto j = i ; j <nums.size();j++){
                if((nums[i] + nums[j]) == target && i != j){
                    result.[0] = i;
                    result.[0] = j;
                    break;
                } 
            }
        }
        return result;
    }
};