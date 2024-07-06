// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t i=0;
        for(;i<nums.size();++i){
            if(nums[i] >= target){
                break;
            }
        }
        return i;
    }
};