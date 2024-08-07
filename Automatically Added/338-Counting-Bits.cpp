class Solution {
    int count_ones(int n){
        int ones = 0;
        while(n){
            if(n%2 == 1)
                ones++;
            n /=2;
        }
        return ones;
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