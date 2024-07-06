// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp={nums[0]};
        for(int i = 1 ; i < nums.size();++i){
            if(temp.back() != nums[i]){
                temp.push_back(nums[i]);
            }
        }
        nums=temp;
        return temp.size();
    }
};