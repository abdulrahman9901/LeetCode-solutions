class Solution {
    int count_ones(int n){
        int c = 0;
        while(n){
            n &=(n-1);
            c++;
        }
        return c;
    }
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int j=0;j<n+1;j++){
            res[j] = count_ones(j);
        }
        return res;
    }
};