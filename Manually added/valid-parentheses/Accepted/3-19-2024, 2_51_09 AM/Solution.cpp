// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        deque<char> stack;
        for(char c :s){
            if(c =='(' || c == '{' || c == '['){
                stack.push_back(c);
            }else {
               if (!stack.empty() && (c ==')' &&  stack.back() =='(' || c ==']' &&  stack.back() =='[' || c =='}' &&  stack.back() =='{'))   
                stack.pop_back();
                else 
                    return false;
            }
        }
        return stack.empty();
    }
};