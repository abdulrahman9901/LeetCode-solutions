// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> row(10,false),column(10,false);
        vector<vector<bool>> subGrid(9,vector<bool>(10,false));
        for(int i = 0 ; i < 9; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j] <= '9' && board[j][i] <= '9' ){
                    if(board[i][j] !=  '.' ){
                        if(row[int(board[i][j] - '0')]){
                            return false;
                        }else{
                            row[int(board[i][j] - '0')] = true;
                        }
                        int gridNum = (i/3) * 3 + (j/3);
                        if(subGrid[gridNum][int(board[i][j] - '0')]){
                            return false;
                        }else{
                            subGrid[gridNum][int(board[i][j] - '0')] = true;
                        }

                    }
                        
                    if(board[j][i] != '.' ) 
                    { 
                        if(column[int(board[j][i] - '0')]){
                            return false;
                        }else{
                            column[int(board[j][i] - '0')] = true;
                        }
                    }
                    
                }else {
                    return false;
                }
            }
            cout<<endl;
            row.assign(10,false);
            column.assign(10,false);
        }
        return true;
        
    }
};