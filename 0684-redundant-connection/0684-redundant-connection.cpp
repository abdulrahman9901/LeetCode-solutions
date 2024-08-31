class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n + 1, 1); 
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int a) {            
            if (parent[a] != a) {
                parent[a] = find(parent[a]);
            }
            return parent[a];
        };

         
        function<bool(int,int)> Union = [&](int a , int b) {       
            int rootA = find(a);  
            int rootB = find(b);  
            if( rootA != rootB){
                if(rank[a] >= rank[b]){
                    rank[a] += rank[b];
                    parent[rootB] = parent[rootA];
                }else {
                    rank[b] += rank[a];
                    parent[rootA] = parent[rootB];
                }
            }else {
                return false;
            }
            return true;
        };

        for(auto edge:edges){
            if(!Union(edge[0],edge[1]))
                return edge;
        }
        
        return {};
    }
};
