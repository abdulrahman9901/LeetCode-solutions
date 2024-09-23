class Solution {
    int findPaths(int m, int n,int posx,int posy,vector<vector<int>> &count){
        if(posx >= m  || posy >= n)
            return 0;
        if(posx == m - 1 && posy == n-1){
            return 1;
        }
        if (count[posx][posy] == 0)
            count[posx][posy] = findPaths(m,n,posx+1,posy,count) + findPaths(m,n,posx,posy+1,count);
            
        return count[posx][posy];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> count(m, vector<int>(n, 0));
        return findPaths(m,n,0,0,count);
    }
};