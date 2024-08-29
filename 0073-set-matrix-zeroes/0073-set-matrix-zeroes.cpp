class Solution {
    int m , n ;
    map<int,bool> zeroCol,zeroRow;
    void setZero(vector<vector<int>>& matrix , int i , int j){
        if(!zeroRow[i]){
            for(int x = 0 ; x < n ; ++x){
                matrix[i][x] = 0;
            }
            zeroRow[i] = true;
        }
        if(!zeroCol[j]){
            for(int x = 0 ; x < m ; ++x){
                matrix[x][j] = 0;
            }
            zeroCol[j] = true;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        this->n = matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(matrix[i][j] == 0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto zero:zeros){
            setZero(matrix,zero.first,zero.second);
        }
    }
};