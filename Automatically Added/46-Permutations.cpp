class Solution {
    vector<int> nums ;
    void dfs(vector<vector<int>> & res , vector<int> set , vector<bool> visited ) {
        if(set.size() == nums.size()){
            res.push_back(set);
            return;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(visited[i])
                continue;
            visited[i] = true;
            set.push_back(nums[i]);
            dfs(res,set,visited);
            set.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<vector<int>> res ;
        vector<bool> visited(nums.size(), false);
        dfs(res,{},visited);
        return res;
    }
};