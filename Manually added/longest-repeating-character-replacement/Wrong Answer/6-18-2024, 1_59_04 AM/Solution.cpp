// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> cc;
        int l=0 , r=0 , maxCount=0;
        while(r < s.length()){
            cc[s[r]]++;
            if(cc[s[r]] > maxCount)
                maxCount = cc[s[r]];
            if((r-l) - maxCount > k ){
                cc[s[l]]--;
                l++;
                maxCount = max_element(cc.begin(), cc.end(), [](auto a ,auto b){
                    return a.second < b.second;
                })->second;
                cout<<maxCount<<endl;
            }
            r++;
        }
        return r-l;
    }
};