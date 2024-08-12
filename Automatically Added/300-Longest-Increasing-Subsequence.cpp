class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq(nums.size(),0);
        seq[nums.size()-1] = 1;
        int maxVal=1;
        for(int i = nums.size()-1 ; i >=0;--i){
            seq[i] = 1;
            for(int j = i+1 ; j < nums.size();j++){
                if(nums[i] < nums[j]){
                    seq[i] = max(seq[i],seq[j]+1);
                }
            }
            if(maxVal < seq[i]) 
                maxVal = seq[i];       
        }
        return maxVal;
    }
};