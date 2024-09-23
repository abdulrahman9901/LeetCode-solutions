class Solution {
    void dfs(map<string,priority_queue<string,vector<string>,greater<string>>> &edges ,vector<string> &res,string current){
        while(!edges[current].empty()){
            string node = edges[current].top();
            edges[current].pop();
            dfs(edges,res,node);
        }
        res.push_back(current);
    };
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,priority_queue<string,vector<string>,greater<string>>> edges;
        vector<string> res;
        for(int i = 0 ; i < tickets.size();++i){
            edges[tickets[i][0]].push(tickets[i][1]);
        }
        dfs(edges,res,"JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};