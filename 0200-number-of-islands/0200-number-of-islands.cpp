class Solution {
    int m,n;
    void dfs(int x ,int y,vector<vector<char>> &grid){
        if(x >= m || x < 0  || y >= n || y < 0 || grid[x][y] == '0')
            return ;

        grid[x][y] = '0';

        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
        dfs(x,y-1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count=0;
        this->m = grid.size();
        this->n = grid[0].size();
        for(int i = 0 ; i < m ; ++i)
            for(int j = 0 ; j < n ; ++j)
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j,grid);  
                }
        return count;
    }
};