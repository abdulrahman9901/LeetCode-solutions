// https://leetcode.com/problems/length-of-last-word

#include <cstring>  
class Solution {
public:
    int lengthOfLastWord(string s) {
        string word;
        for(std::istringstream is( s ); is >> word;)
        {
            std::cout << word << '\n';
        }
        return word.length();
    }
};