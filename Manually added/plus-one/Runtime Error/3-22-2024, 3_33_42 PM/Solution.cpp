// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        size_t i = digits.size()-1;
        for(;i>=0;--i){
                if(digits[i] < 9){
                    digits[i]++;
                }else {
                    digits[i]=0;
                }
            }
        if(digits[0] == 0){
            digits.push_back(0);
            
        }
        return digits;
    }
};