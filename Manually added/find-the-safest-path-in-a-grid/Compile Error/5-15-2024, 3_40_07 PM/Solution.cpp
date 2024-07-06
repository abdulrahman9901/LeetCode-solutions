// https://leetcode.com/problems/find-the-safest-path-in-a-grid

class Solution {
public:
    int Manhattan_distance(int n ,int x,int y){
        return abs(n - 1 - x) + abs(n - 1 - y);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(),i=0,j=0;
        map<pair<int,int>,int> path;
        bool reached = false;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return 0;
        }
        int tempDist=10*n;
        
        while(!reached){
            if(!grid[i+1][j]){if(tempDist<Manhattan_distance(n,i+1,j)){tempDist=Manhattan_distance(n,i+1,j);temp={i+1,j};i++;}}
            if(i-1 >= 0 && !grid[i-1][j]){if(tempDist < Manhattan_distance(n,i-1,j)){temp={i-1,j};i--;}}
            if(!grid[i][j+1]){if(tempDist < Manhattan_distance(n,i,j+1)){tempDist = Manhattan_distance(n,i,j+1);temp={i,j+1};j++;}}
            if(j-1 >= 0 && !grid[i][j-1]){if(tempDist<Manhattan_distance(n,i,j-1)){tempDist=Manhattan_distance(n,i,j-1);temp={i,j-1};j--;}}
            path[std::make_pair(temp.first,temp.second)] = tempDist;
            cout<<temp.first<<" , "<<temp.second<<tempDist <<endl;
            if(temp.first == n-1 && temp.second == n-1){
                reached = true;
            }
        }
        return 2;
    }
};