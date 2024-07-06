// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
    std::string s = std::to_string(x);
    size_t i = 0 , len = s.length()-1 ;
    // len = s.length()-1 ;
    while(i != len-i && i < len-i){ 
        if(s[i] != s[s.length()-i-1])
            return false;
        i++;
    }
    return true;
    }
};