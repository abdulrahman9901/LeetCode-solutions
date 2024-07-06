// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t last = nums.size()-1 , k=0;
        for(size_t i=0 ;i<=last;++i){
            if(nums[i] == val){
                while(nums[last] == val)
                    last--;
                nums[i]=nums[last];
                last--;
            }
            k++;
        }
        return k;
    }
};