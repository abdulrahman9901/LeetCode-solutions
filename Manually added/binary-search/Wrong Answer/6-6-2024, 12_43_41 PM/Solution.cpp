// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1,mid= nums.size()/2;
        while(left < right){
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