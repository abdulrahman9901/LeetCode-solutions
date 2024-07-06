// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator st = numbers.begin(),end = numbers.end() -1 ; 
        while(st != end){
            if((*st) + (*end) == target ){
                return {1 + static_cast<int>(st - numbers.begin()),1 + static_cast<int>(end - numbers.begin())};
            }else if((*st) + (*end) < target) {
                st++;
            }else {
                end--;
            }
        }
        return{};
    }
};