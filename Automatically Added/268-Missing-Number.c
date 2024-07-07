int compare(const void * a , const void * b){
    return *((int*)a) - *((int*)b);
}

int missingNumber(int* nums, int numsSize) {
    int i = 1;
    qsort(nums,numsSize,sizeof(int),compare);
    for(; i < numsSize ; ++i){
        if(nums[i] != nums[i-1]+1){
            return nums[i-1]+1;
        }
    }

    if(numsSize != nums[i-1])
        return numsSize;

    return 0;
}