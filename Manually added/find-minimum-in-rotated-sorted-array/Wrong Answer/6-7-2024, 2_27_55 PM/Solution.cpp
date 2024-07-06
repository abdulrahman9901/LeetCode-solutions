// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0 , right = nums.size()-1;
        int min = 5001 , mid;
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] < min){
                min = nums[mid] ;
                cout<<min<<endl;
            }
            if(nums[left] <= nums[right]){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return min;
    }
};