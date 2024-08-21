class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int j=1;j<=n;j++){
            res[j] = res[j/2] + j%2;
        }
        return res;
    }
};