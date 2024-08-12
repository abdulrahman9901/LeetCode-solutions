#include<algorithm>
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int numSum = std::accumulate(nums.begin(),nums.end(),0);
        if(numSum % 2 !=0)
            return false;
        set<int> dp={0};
        for(int i = nums.size()-1;i>=0;--i){
            set<int> nextdp = dp;  
            for(auto t : dp){
                nextdp.insert(t+nums[i]);
            }
            dp=nextdp;
        }
        if (dp.find(numSum/2) != dp.end()) {
            return true;
        }
        return false;
    }
};