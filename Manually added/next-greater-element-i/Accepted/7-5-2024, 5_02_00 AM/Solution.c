// https://leetcode.com/problems/next-greater-element-i

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare (const void * p , const void * q){
    return *((int*)p) - *((int*)q);
};

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int * res = (int*) calloc(nums1Size,sizeof(int));
    int found = 0 , last = 0;
    *returnSize = nums1Size;
    for(int i = 0 ; i < nums1Size ; ++i){
        res[i] = -1;found = 0;
        for(int j = 0  ; j < nums2Size ; ++j){
            if(nums1[i] == nums2[j]){
                found = 1;
            }
            if(found && nums1[i] < nums2[j]){
                res[last] = nums2[j];
                break;
            }
        }
        last++;
    }
    return res;
}