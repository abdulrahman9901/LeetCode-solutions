// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
            return !::isalpha(c) && !::isdigit(c);
        }), s.end());
            
        for(int i=0  ; i<s.length();++i){
            if (!::isalpha(s[i]) && !::isdigit(s[i]) )
            {
                cout<<s[i]<<endl;
                s.erase(i, 1);
                cout<<s<<endl;
            }
        }

        for(int i=0  ; i<s.length();++i){
            if(s[i]!=s[s.length()-i-1]){
                return false;
            }
        }
    return true;
    }
};