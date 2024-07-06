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
                    int x = i ,st=ceil(log2(i));
                  while(x>0){
                    cout<<x<<st<<endl;
                    x-=pow(2,st);
                    st--;
                    count[i]++;
                    cout<<x<<st<<endl;
                  }
                }
            }
        }
        return count;
    }
};