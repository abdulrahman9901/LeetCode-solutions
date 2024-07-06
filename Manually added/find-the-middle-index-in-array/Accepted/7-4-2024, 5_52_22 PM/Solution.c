// https://leetcode.com/problems/find-the-middle-index-in-array

int findMiddleIndex(int* nums, int numsSize) {;
    int lSum = 0 , res = 0;
    for(int i =0 ;i<numsSize;i++){
        res = res + nums[i];
    }
    for(int i =0 ;i<numsSize;i++){
        if(lSum * 2 == res - nums[i] )
            return i;
        lSum+=nums[i];
    }
    return -1 ;
}