// https://leetcode.com/problems/kth-largest-element-in-an-array

int compare (void * q , void * p){
    return *((int*)p) - *((int*)q); 
}
int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums,numsSize,sizeof(int),compare);
    return nums[k-1];
}