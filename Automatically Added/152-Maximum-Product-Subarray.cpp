class Solution {
public:
    int maxProduct(vector<int>& nums) {

        double maxVal=nums[0];
        double minVal=nums[0];
        double result=nums[0];
        for(int i = 1; i < nums.size() ; ++i){
            if(nums[i] < 0)
                swap(minVal,maxVal);
            
            maxVal=max(maxVal * nums[i],(double)nums[i]);
            minVal=min(minVal * nums[i],(double)nums[i]);

            result = max(maxVal,result);
        }
        return result;
    }
};