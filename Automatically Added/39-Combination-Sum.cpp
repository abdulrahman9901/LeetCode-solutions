class Solution {
    vector<int> candidates ;
    void dfs(int target , vector<vector<int>> &res ,vector<int> set , int st){
        if(target == 0){
            res.push_back(set);
            return;
        }else if (target < 0){
            return;
        }

        for(int i = st ; i < candidates.size() ;++i){
            set.push_back(candidates[i]);
            dfs(target - candidates[i] ,res,set,i);
            set.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        this->candidates = candidates;
        dfs(target,res,{},0);
        return res;
    }
};