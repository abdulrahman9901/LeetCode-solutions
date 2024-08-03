class Solution {
    vector<vector<string>> res;
    string str;
bool isPalindrome(string s) {

    if (s == "")
        return false;

    if(s.size() == 1)
        return true;

    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }

    return true;
}
    void dfs(vector<vector<string>>& res , string s,int st, vector<string> subset){

        if(isPalindrome(s)){
            subset.push_back(s);
        }else if(s != ""){
            return;
        }

        if(str.size() == st)
            res.push_back(subset);

        for(int i = 1; st + i <= str.size()  ;++i){
            string newStr = str.substr(st, i);
            dfs(res,newStr,st + i,subset);
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->str = s;
        dfs(res,"",0,{});
        return res;
    }
};