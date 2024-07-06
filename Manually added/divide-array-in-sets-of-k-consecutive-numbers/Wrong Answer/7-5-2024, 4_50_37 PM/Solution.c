// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

bool isPossibleDivide(int* nums, int numsSize, int k) {
    if(1 == k )
        return true;
    if(numsSize % k == 0 )
        return true;
    else 
        return false;
}