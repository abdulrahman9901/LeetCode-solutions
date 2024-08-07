class Solution {
    int rob1(vector<int>& nums){
        if(nums.size() == 1)
            return nums[0];
        
        int r0 = nums[0];
        int r1 = max(nums[1],nums[0]);

        for(int i =2;i < nums.size();++i){
            int temp = max(nums[i]+r0,r1);
            r0 = r1;
            r1=temp;
        }

        return r1;
       }
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];
        
        vector<int> skipFirst(nums.begin()+1,nums.end());
        vector<int> skipLast(nums.begin(),nums.end()-1);
        
        return max(rob1(skipFirst),rob1(skipLast));
    }
};