// https://leetcode.com/problems/power-of-two

bool isPowerOfTwo(int n) {
    if(n==1)
        return true;
    return n%2 == 0;
}