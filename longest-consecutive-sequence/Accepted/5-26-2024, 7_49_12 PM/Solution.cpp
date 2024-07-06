// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        size_t seqCount = 1 , maxSeq = 1;
        size_t len = nums.size();
        if(len <= 1){
            return len;
        }
        sort(nums.begin(),nums.end());
        for(size_t i = 1 ; i<len;++i){
            if(nums[i-1] == (nums[i] -1)){
                seqCount++;
            }else if(nums[i-1] == nums[i]){
                continue; 
            }else {
                if(seqCount > maxSeq)
                    maxSeq = seqCount ;
                seqCount = 1 ;
            }
        }
        return seqCount > maxSeq ? seqCount : maxSeq ;
    }
};