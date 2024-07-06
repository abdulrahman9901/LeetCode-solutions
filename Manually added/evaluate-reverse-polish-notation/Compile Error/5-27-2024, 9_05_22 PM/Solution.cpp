// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool isOperator(string token) {
        if (token == '+' || token == '-' || token == '*' || token == '/') {
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums ;
         int temp;
        for(auto token :tokens ){
            if(isOperator(token)){
                temp = nums.top();
                nums.pop();
                if(token == "+"){         
                    temp += nums.top();
                }
                else if(token == "-"){
                    temp = nums.top() - temp;
                }
                else if(token == "*"){
                    temp *= nums.top();
                }
                else if(token == "/"){
                    temp = nums.top() / temp;
                }
                nums.pop();
                nums.push(temp);
            }
            else
                nums.push(stoi(token));
            }
            return nums.top();
    }
};