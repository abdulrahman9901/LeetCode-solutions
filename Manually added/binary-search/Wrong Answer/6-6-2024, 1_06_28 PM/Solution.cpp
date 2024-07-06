// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1,mid;
        if(nums.size() == 1 && nums[0] == target)
            return 0;
        while(left < (right - 1)){
            mid= (right + left)/2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                left = mid ;
            }else {
                right = mid ;
            }
        }
        return -1;
    }
};