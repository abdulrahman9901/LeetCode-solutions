class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> maxEle(nums.size(),0);
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        maxEle[0] = nums[0];
        int maxSum = maxEle[0];
        for(int i=1;i<nums.size();++i){
            maxEle[i] = max(nums[i],maxEle[i-1]+nums[i]);
            maxSum = max(maxSum,maxEle[i]);
        }

        return maxSum;
    }
};