class Solution {
    vector<int> candidates;
    void dfs(vector<vector<int>> &res , vector<int> subset , int target , int st){
        if(target < 0){
            return;
        }
        if(target == 0) {
            res.push_back(subset);
            return;
        }
        for(int i = st ; i<candidates.size(); ++i){
            if(i > st  && candidates[i] == candidates[i-1])
                continue;
                
            subset.push_back(candidates[i]);    
            dfs(res,subset,target - candidates[i] , i+1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->candidates = candidates;
        sort(this->candidates.begin(),this->candidates.end());
        vector<vector<int>> res ;
        vector<int> subset;
        dfs(res,subset,target,0);
        return res; 
    }
};