// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i = 0;i<nums.size();++i){
            int num = 1;
            for(int j = 0;j<nums.size();++j){
                if(i==j)
                    continue;
                num*=nums[j];
            }
            res.push_back(num);
        }
        return res;
    }   
};