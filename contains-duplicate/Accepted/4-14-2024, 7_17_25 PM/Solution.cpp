// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,size_t>lookup;
        for(auto num:nums){
            if(lookup[num])
                 return true ;
            else
                lookup[num]++ ;  
        }
        return false;
    }
};