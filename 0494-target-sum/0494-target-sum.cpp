class Solution {
    int dfs(vector<int>& nums, vector<vector<int>>& dp, int index, int total, int target, int offset) {
        if (index == nums.size()) {
            return total == target ? 1 : 0;
        }
        
        if (dp[index][total + offset] != -1) {
            return dp[index][total + offset];
        }

        int add = dfs(nums, dp, index + 1, total + nums[index], target, offset);
        int subtract = dfs(nums, dp, index + 1, total - nums[index], target, offset);

        dp[index][total + offset] = add + subtract;

        return dp[index][total + offset];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);  
        int offset = sum;  
        
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return dfs(nums, dp, 0, 0, target, offset);
    }
};