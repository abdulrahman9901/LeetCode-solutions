// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void helper(vector<string> &res ,string str , int close , int open , int n){
        if(open < n)
            helper(res ,str+'(',close,open+1,n);
        if (close < open) 
            helper(res ,str+')',close+1,open,n);
        if(str.size() == 2*n)
            res.push_back(str);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res ;
        helper(res ,"(",0,1,n);
        return res;
    }
};