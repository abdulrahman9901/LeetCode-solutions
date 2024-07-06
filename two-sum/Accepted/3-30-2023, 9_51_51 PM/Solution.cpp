// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto temp = nums;
        int indx1 = nums.size() , indx2 = nums.size()  ;
        for(auto i = 0 ; i <nums.size();i++){
            for(auto j = i ; j <nums.size();j++){
            if((temp[i] + temp[j]) == target && i != j){
                indx1 =  i;
                indx2 =  j;
                break;
            }
        }
        }
        vector<int> result {indx1,indx2};
        return result;
    }
    
};