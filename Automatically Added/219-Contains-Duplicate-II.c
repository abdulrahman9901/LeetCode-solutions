struct Node {
    int val;
    int idx;
};

int compare(const void * a , const void * b){
    return ((struct Node*)a)->val - ((struct Node*)b)->val;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    struct Node nodeArr[numsSize];
    int i = 0;

    if(numsSize == 1 || k == 0 )
        return false;

    if(numsSize <= k)
        k = numsSize - 1;

    for(; i < numsSize ; ++i){
        nodeArr[i].val = nums[i];
        nodeArr[i].idx = i;
    }
    
    qsort(nodeArr,numsSize,sizeof( struct Node),compare);

    i=1;
    for(; i < numsSize ; ++i){
        if(nodeArr[i].val == nodeArr[i-1].val && abs(nodeArr[i].idx - nodeArr[i-1].idx) <=k)
            return true;
    }

    return false;
}