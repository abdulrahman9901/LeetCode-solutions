// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() , prod = 1;
        vector<int> res(n,0), zeros;
        // for(int i = 0;i<nums.size();++i){
        //     int num = 1;
        //     for(int j = 0;j<nums.size();++j){
        //         if(i==j)
        //             continue;
        //         num*=nums[j];
        //     }
        //     res.push_back(num);
        // }

        for(int j = 0;j<n;++j){
            if(0==nums[j]){
                zeros.push_back(j);
                continue;
            }else
                prod*=nums[j];
        }
        if(zeros.size() == 1){
            res[zeros[0]] = prod;
        }else if (zeros.size() == 0){
            for(int j = 0;j<n;++j){
                res[j] = prod/nums[j];
            }
        }
        return res;
    }   
};