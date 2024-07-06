// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty())
            return ;
        else if(nums2.empty())
            return;
        
        for(int i=0 ;i<n;++i)
            nums1[m++]=nums2[i];
        sort(nums1.begin(),nums1.end());
    }
};