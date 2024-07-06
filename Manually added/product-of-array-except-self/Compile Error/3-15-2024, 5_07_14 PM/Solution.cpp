// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t zeroIndex=nums.size()+1;
        bool zero=0;
        int malval=1;
        for(auto num:nums){
            if(num)
                malval*=num;
        }
    }
};