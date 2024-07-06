// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t index = 0;
        for(size_t i = 1 ; i < nums.size();++i){
            if(nums[index] != nums[i]){
                index++;
                if(index!= i)
                    nums[index] = nums[i];
                }
        }
        index++;
        nums.erase(nums.begin()+index, nums.end());
        return index;
    }
};