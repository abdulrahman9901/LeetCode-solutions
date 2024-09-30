class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist (n,vector<int>(n,INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto [currentLevel , x , y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1) {
                return currentLevel;
            }

            for(auto dir:directions){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    int newLevel = max(currentLevel, grid[nx][ny]);

                    if (newLevel < dist[nx][ny]) {
                        dist[nx][ny] = newLevel;
                        pq.push({newLevel, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};