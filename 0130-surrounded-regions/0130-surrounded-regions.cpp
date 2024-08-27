class Solution {
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& visited, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        visited[i][j]=true;

        vector<int> dir = {-1, 0, 1, 0, -1};  

        for (int d = 0; d < 4; ++d) {
            int ni = i + dir[d];
            int nj = j + dir[d + 1];
            
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && !visited[ni][nj] && board[i][j]=='O') {
                dfs(board,visited, ni, nj);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

         for (int i = 0; i < rows; ++i) {
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(board,visited,i,0);
            }
            if(board[i][cols-1]=='O' && !visited[i][cols-1]){
                dfs(board,visited,i,cols-1);
            } 
        }
         for (int i = 0; i < cols; ++i) {
            if(board[0][i]=='O' && !visited[0][i]){
                dfs(board,visited,0,i);
            }
            if(board[rows-1][i]=='O' && !visited[rows-1][i]){
                dfs(board,visited,rows-1,i);
            } 
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';  
                }
            }
        }
    }
};