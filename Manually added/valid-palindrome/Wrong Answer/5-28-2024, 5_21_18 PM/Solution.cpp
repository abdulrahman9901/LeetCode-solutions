// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int i=0  ; i<s.length();++i){
            if (!::isalpha(s[i]))
            {
                s.erase(i, 1);
                cout<<s<<endl;
            }
        }

        for(int i=0  ; i<s.length();++i){
            if(s[i]!=s[i+s.length()-1]){
                cout<<s[i]<<" "<<s[-1+s.length()-1]<<endl;
                return false;
            }
        }
    return true;
    }
};