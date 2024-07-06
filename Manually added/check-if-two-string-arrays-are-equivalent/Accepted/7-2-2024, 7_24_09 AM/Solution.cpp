// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
    string toSingleStr(vector<string>& word){
        string w = "";
        for(auto str:word)
            w+=str;
        return w;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 , w2 ;
        int x =0 , y = 0 ;
        w1 = toSingleStr(word1);
        w2 = toSingleStr(word2);
        if(w1.size() != w2.size())
            return  false;
        while(x < w1.size()){
            if(w1[x++]!=w2[y++])
                return false;
        }
        return true;
    }
};