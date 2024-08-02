
class Solution {
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    string word;
    int m , n;
    bool dfs(int r , int c,int i){

        if(i == word.size())
            return true;

        if(r >= m || c >= n || r < 0 || c < 0 || visited[r][c] || board[r][c] != word[i] )
            return false;


        visited[r][c] = true;

        bool found =  
                dfs(r-1,c,i+1) || dfs(r+1,c,i+1) || 
                dfs(r,c-1,i+1) || dfs(r,c+1,i+1) ;
        
        visited[r][c] = false;


        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        this->m = board.size();
        this->n = board[0].size();
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
    return false;
    }
};