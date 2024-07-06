// https://leetcode.com/problems/find-the-middle-index-in-array

int findMiddleIndex(int* nums, int numsSize) {
    int l = 0 , r = numsSize - 1;
    int rSum = 0 , lSum = 0;
    if(numsSize == 1 )
        return 0;
    else if (numsSize == 2)
        return -1;
    while(l <= r){
        if(lSum > rSum){
            rSum+=nums[r--];
            printf("rSum : %d %d \n",rSum,r);
        }else{
            lSum+=nums[l++];
            printf("lSum : %d %d \n",lSum,l);
        }
        
        if(lSum == rSum)
            return r;
        if(r+1 < numsSize && lSum == rSum - nums[r+1])
            return r+1;
    }
    return -1 ;
}