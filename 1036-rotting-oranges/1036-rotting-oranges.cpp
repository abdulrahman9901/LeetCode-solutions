class Solution {
    int rows ; 
    int cols ; 
    int minTime ; 
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0 , time = 0;
        this->rows = grid.size(); 
        this->cols = grid[0].size();
        queue<pair<int,int>> rottenQ ; 
        for(int i=0;i < rows;++i){
            for(int j=0;j < cols;++j){
                if(grid[i][j] == 2){
                    rottenQ.push({i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }   
        cout<<fresh<<rottenQ.size()<<endl;
        while (fresh && !rottenQ.empty()){
            int Qlen = rottenQ.size();
            for(int i=0;i<Qlen;++i){
                cout<<fresh<<Qlen<<endl;
                auto temp = rottenQ.front();
                rottenQ.pop();
                if(temp.first-1 >= 0 && grid[temp.first-1][temp.second] == 1){
                    rottenQ.push({temp.first-1,temp.second});
                    grid[temp.first-1][temp.second] = 2;
                    fresh--;    
                }
                if(temp.first+1 < rows && grid[temp.first+1][temp.second] == 1){
                    rottenQ.push({temp.first+1,temp.second});
                    grid[temp.first+1][temp.second] = 2;
                    fresh--;
                }
                if(temp.second-1 >= 0 && grid[temp.first][temp.second-1] == 1){
                    rottenQ.push({temp.first,temp.second-1});
                    grid[temp.first][temp.second-1] = 2;
                    fresh--;
                }
                if(temp.second+1 < cols && grid[temp.first][temp.second+1] == 1){
                    rottenQ.push({temp.first,temp.second+1});
                     grid[temp.first][temp.second+1] = 2;
                    fresh--;
                }
            }
            time++;
        }
    if(fresh)
        return -1;
    return time;
    }
};