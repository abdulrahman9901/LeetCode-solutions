// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.empty()){
        sort(nums.begin(),nums.end());
        int count=1;
        for (auto num :nums){
            if(num<=0){
                continue;
            }else{
                if(count< num){
                    return count;
            }else{
                    count++;
                }
        }
    }
        if(nums[nums.size()-1]>0)
              return count;
  }
     return 1;     
}
};