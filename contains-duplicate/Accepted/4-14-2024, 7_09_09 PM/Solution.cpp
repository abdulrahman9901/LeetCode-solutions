// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,size_t>lookup;
        for(auto num:nums){
            lookup[num]++;
            if(lookup[num]>1)
                return true;
        }
        return false;
    }
};