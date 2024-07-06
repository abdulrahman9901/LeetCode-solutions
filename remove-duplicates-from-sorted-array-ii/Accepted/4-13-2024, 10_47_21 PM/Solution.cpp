// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t i = 0 , j = 1;
        bool isTwice=true;
        for(;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]= nums[j];
                isTwice=true;
            }else if (isTwice){
                i++;               
                nums[i]= nums[j];
                isTwice=false;
            }
        }
        return i+1;
    }
};