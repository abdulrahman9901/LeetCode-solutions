// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int seqCount = 1 , maxSeq=1;
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i<nums.size();++i){
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