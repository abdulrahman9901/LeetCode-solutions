// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto temp = nums;
        sort(temp.begin(),temp.end());
        vector<int> result ;
        for(auto i = 0 ; i <nums.length();i++){
            if(temp[i] == temp[temp.length()- 1 - i]){
               auto indx1 =  find(nums.begin(),nums.end(),temp[i]);
               auto indx2 =  find(nums.begin(),nums.end(),temp[nums.length()- 1 - i]);
               result.push_back(indx1);
               result.push_back(indx2);
               break;
            }
        }
            return result;
    }
    
};