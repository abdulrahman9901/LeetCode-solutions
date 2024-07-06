// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        map<int,int>  m ;
        for(int i = 0 ; i < len ;++i){
            if(m[nums[i]] == 0)
                m[nums[i]]++;
            else 
                return nums[i];
        }
        return 0;
    }
};