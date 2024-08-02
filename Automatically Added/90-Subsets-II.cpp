class Solution {
    vector<int> nums ;
    void dfs(vector<vector<int>> & res , vector<int> subset , int index){

        if(index >= nums.size()){
            res.push_back(subset);
            return ;
        }

        subset.push_back(nums[index]);

        dfs(res,subset,index+1);

        subset.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        dfs(res,subset,index+1);
    
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        vector<vector<int>>  res ;
        dfs(res,{},0);
        return res;
    }
};