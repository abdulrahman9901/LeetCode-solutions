// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        bool solved = false;
        int st = 0, end = numbers.size()-1;
        while(!solved){
            if(numbers[st] + numbers[end] == target)
                solved = true;
           else if(numbers[st] + numbers[end] > target)
                end--;
            else
                st++;
        }     
        return {st+1,end+1};
    }
};