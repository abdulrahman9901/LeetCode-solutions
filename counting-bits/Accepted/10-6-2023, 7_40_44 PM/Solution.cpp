// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1,0);
        int num  ;
        for(size_t i = 1 ; i <= n ;++i){
            num = i ;
            while(num !=0){
                count[i]+= num%2;
                num/=2; 
            }
         }
        return count;
    }
};