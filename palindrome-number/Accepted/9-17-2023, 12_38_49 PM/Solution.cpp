// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
    std::string s = std::to_string(x);
    int i =0;
    while(i != s.length()-i-1 && i < s.length()-i-1){ 
        if(s[i] != s[s.length()-i-1])
            return false;
        i++;
    }
    return true;
    }
};