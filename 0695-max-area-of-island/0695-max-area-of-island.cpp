class Solution {
    vector<vector<int>> grid;
    int m, n;
    void dfs(int x, int y , int &count) {
        if (x >= m || x < 0 || y >= n || y < 0 || grid[x][y] == 0)
            return;
        
        grid[x][y] = 0;
        count++;
        dfs(x + 1, y,count);
        dfs(x - 1, y,count);
        dfs(x, y + 1,count);
        dfs(x, y - 1,count);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        this->grid = grid;
        this->m = grid.size();        
        this->n = grid[0].size();     

        int count = 0;  
        int maxCount = 0;  

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (this->grid[i][j] == 1) {
                    count=0;  
                    dfs(i, j,count);
                    if(count > maxCount)
                        maxCount = count;
                }
            }
        }
        return maxCount;
    }
};