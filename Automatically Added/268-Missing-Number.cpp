class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i ;
        for(i = 1 ; i <nums.size();++i){
            if(nums[i] != nums[i-1]+1)
                return nums[i-1]+1;
        }
        return i == nums.size() && nums[i-1] !=nums.size()? nums.size() : 0;
    }
};