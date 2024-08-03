class Solution {
    map<char,string> digitChar = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string digits;
    void dfs(vector<string> &res , int i , string comb){
        if(comb.size() == digits.size() && comb != ""){
            res.push_back(comb);
        }
        for(char c :digitChar[digits[i]]){
            dfs(res,i+1,comb+c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res ;
        this->digits = digits;
        dfs(res,0,"");
        return res;
    }
};