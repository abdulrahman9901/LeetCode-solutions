class Solution {
    void dfs(vector<int>& nums , vector<int> subset , int i, vector<vector<int>> &res){
        if(i >=nums.size()){
            res.push_back(subset);
            return;
        }

        dfs(nums,subset,i+1,res);
        subset.push_back(nums[i]);
        dfs(nums,subset,i+1,res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ;
        dfs(nums,{},0,res);
        return res;
    }
};