// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums ;
         int temp;
        for(auto token :tokens ){
                if(token == "+"){
                    temp = nums.top();
                    nums.pop();
                    temp += nums.top();
                    nums.pop();
                    nums.push(temp);
                }
                else if(token == "-"){
                    temp = nums.top();
                    nums.pop();
                    temp = nums.top() - temp;
                    nums.pop();
                    nums.push(temp);
                }
                else if(token == "*"){
                    temp = nums.top();
                    nums.pop();
                    temp *= nums.top();
                    nums.pop();
                    nums.push(temp);
                }
                else if(token == "/"){
                    temp = nums.top();
                    nums.pop();
                    temp = nums.top() / temp;
                    nums.pop();
                    nums.push(temp);
                }
                else
                    nums.push(stoi(token));
            }
            return nums.top();
    }
};