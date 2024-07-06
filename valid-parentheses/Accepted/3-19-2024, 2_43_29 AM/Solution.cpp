// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c :s){
            if(c =='(' || c == '{' || c == '['){
                stack.push(c);
            }else {
               if (!stack.empty() && (c ==')' &&  stack.top() =='(' || c ==']' &&  stack.top() =='[' || c =='}' &&  stack.top() =='{'))   
                stack.pop();
                else 
                    return false;
            }
        }
        return stack.empty();
    }
};