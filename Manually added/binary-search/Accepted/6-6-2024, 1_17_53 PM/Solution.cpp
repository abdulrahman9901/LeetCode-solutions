// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size(),mid;
        while(left < right){
            mid= (right + left)/2;
            cout<<mid<<endl;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                if(left == mid)
                    break;
                left = mid;
            }else {
                if(right == mid)
                    break;
                right = mid;
            }
        }
        if(nums.size() <= 2 && nums[0] == target)
            return 0;
        return -1;
    }
};