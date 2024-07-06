// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
         if(nums.size() == 1)
            return nums[r] == target ? r : -1;
            while(l < r){
                mid = (r+l)/2;
                cout<<"L : MID : R ==> "<<l<<" : "<<mid<<" : "<<r<<endl;
                cout<<"nums[mid]  : "<<nums[mid] <<" : "<<target<<endl;
                if(nums[mid] == target ){
                    return mid;
                }
                if(nums[mid] < nums[l]){
                    if(target > nums[r] || target < nums[mid]) 
                        r = mid - 1;
                    else
                        l = mid + 1;
                }else{      
                    if(target < nums[l] || target > nums[mid])
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
            }
        cout<<" target : "<<l << mid <<r<<endl;
        return nums[l] == target ? l : -1;
    }
};