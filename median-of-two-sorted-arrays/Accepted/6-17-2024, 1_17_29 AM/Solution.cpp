// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size(), i=0 , j=0; 
        int mn ;
        vector<int> res ;
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                res.push_back(nums1[i++]);
            }else {
                 res.push_back(nums2[j++]);
            }
        }
        if(i < n1)
            for(i ; i < n1;++i)
                res.push_back(nums1[i]);
        else
            for(j ; j < n2;++j)
                res.push_back(nums2[j]);

        mn = res.size();
        cout<<mn<<endl;
        return mn%2 != 0 ? res[mn/2] : (res[mn/2] + res[(mn/2)-1])/2.0 ;
    }
};