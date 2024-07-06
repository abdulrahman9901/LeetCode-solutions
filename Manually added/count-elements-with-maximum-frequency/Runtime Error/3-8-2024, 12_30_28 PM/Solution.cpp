// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        size_t count[100]={0},maxVal = 0 , countVal=0;
        for(size_t i =0 ; i < nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]] > maxVal){
                maxVal = count[nums[i]];
            }
        }
        for(size_t i =0 ; i < nums.size();i++){
            if(count[nums[i]] == maxVal){
                countVal++;
            }
        }
        return countVal ;
    }
};