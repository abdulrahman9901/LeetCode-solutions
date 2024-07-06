// https://leetcode.com/problems/counting-bits

class Solution {
public:
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
    vector<int> countBits(int n) {
        vector<int> count(n+1,0);
        for(size_t i = 1 ; i <= n ;++i){
            count[i] = __builtin_popcount(i);
         }
        return count;
    }
};