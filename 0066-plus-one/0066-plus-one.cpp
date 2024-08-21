class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n=digits.size();
        for(int i=n-1;i>=0;--i){
            if(digits[i]+carry < 10){
                digits[i]+=carry;
                carry=0;
                break;
            }else
                digits[i]=0;
        }
        if(carry){
            vector<int> res (n+1,0);
            res[0] = 1;
            return res;
        }else{
            return digits;
        }
    }
};