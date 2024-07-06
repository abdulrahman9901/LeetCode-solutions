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
            if(isPowerOfTwo(i)){
                count[i]=1;
            }else {
                if(i%2 != 0){
                    count[i]=count[i-1] + 1;
                }else{
                    int x = pow(2,log2(i));
                    count[i] = count[x] + 1 ;
                }
            }
        }
        return count;
    }
};