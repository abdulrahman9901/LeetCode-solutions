// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = nums.size()-1 , k=0;
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0] == val ? 0  : 1;
        for(int i=0 ;i<=last;++i){
            if(nums[i] == val){
                while(last && nums[last] == val )
                    last--;
                if(last)
                { 
                   nums[i]=nums[last];
                    last--;
                }
            }else{
                k++;
            }
        }
        return k;
    }
};