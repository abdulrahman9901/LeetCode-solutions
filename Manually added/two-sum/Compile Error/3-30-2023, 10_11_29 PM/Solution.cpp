// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t i = 0 , j = 0 , len = nums.size() ;
        for(i = 0 ; i <len;i++){
            for(j = i + 1 ; j <len;j++){
                if((nums[i] + nums[j]) == target && i != j){
                    return {i,j};
                } 
            }
        }
        return {-1,-1};
    }
};