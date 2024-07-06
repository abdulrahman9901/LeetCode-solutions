// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0 , j = 0 ; 
        for(i = 0 ; i <nums.size();i++){
            for(j = i + 1 ; j <nums.size();j++){
                if((nums[i] + nums[j]) == target && i != j){
                    return {i,j};
                } 
            }
        }
        return {-1,-1};
    }
};