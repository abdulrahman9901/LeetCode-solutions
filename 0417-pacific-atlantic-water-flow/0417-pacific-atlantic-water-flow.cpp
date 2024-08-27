class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacificReach(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlanticReach(rows, vector<bool>(cols, false));
        
        vector<vector<int>> result;
        
        for (int i = 0; i < rows; ++i) {
            dfs(heights, pacificReach, i, 0);           
            dfs(heights, atlanticReach, i, cols - 1);    
        }
        for (int j = 0; j < cols; ++j) {
            dfs(heights, pacificReach, 0, j);
            dfs(heights, atlanticReach, rows - 1, j);   
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacificReach[i][j] && atlanticReach[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& oceanReach, int i, int j) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        oceanReach[i][j] = true;
        
        vector<int> dir = {-1, 0, 1, 0, -1};  

        for (int d = 0; d < 4; ++d) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                !oceanReach[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, oceanReach, ni, nj);
            }
        }
    }
};
