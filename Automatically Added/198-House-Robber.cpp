class Solution {
public:
    int rob(vector<int>& nums) {   
        if(nums.size() == 1)
            return nums[0];

        if(nums.size() >= 2)
            nums[1]=max(nums[0],nums[1]);

        int i = 2; 
        for (; i < nums.size();++i) {
            nums[i] = max(nums[i-2] + nums[i], nums[i-1]);
        }
        
        return nums[i-1];
    }
};
