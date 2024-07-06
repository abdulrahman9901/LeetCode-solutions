// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator pos ; 
       for(size_t i = 0 ; i < numbers.size() ; ++i){
           if((target * numbers[i]) >= 0){
            pos = find(numbers.begin() + i + 1 ,numbers.end(),(target - numbers[i]));
           if(pos != numbers.end()){
               return { static_cast<int>(i) +1 ,  static_cast<int>(pos-numbers.begin()) +1 };
           }
        }
       } 
       return{0,0}; 
    }
};