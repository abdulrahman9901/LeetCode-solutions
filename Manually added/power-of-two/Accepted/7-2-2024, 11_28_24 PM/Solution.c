// https://leetcode.com/problems/power-of-two

bool isPowerOfTwo(int n) {
    for(long i = 1 ; i <= n ;i=i*2){
        if(i == n)
            return true;
    }
    return false;
}