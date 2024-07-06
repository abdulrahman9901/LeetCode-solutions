// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 1 ; i < nums.size();++i){
            if(nums[index] != nums[i]){
                index++;
                if(index!= i)
                    nums[index] = nums[i];
                }
        }
        index++;
        nums={nums.begin() , nums.begin() +index};
        return index;
    }
};