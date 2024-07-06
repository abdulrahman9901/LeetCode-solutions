// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> row(10,false),column(10,false),sub(10,false);
        for(int i = 0 ; i < 9; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j] <= '9' && board[j][i] <= '9' ){
                    if(board[i][j] !=  '.' ){
                        if(row[int(board[i][j] - '0')]){
                            return false;
                        }else{
                            row[int(board[i][j] - '0')] = true;
                        }
                    }
                        
                    if(board[j][i] != '.' ) 
                    { cout<<board[j][i]<<" ";
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