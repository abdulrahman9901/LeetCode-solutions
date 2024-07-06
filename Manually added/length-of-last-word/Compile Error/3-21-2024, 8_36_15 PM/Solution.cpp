// https://leetcode.com/problems/length-of-last-word

#include <cstring>  
class Solution {
public:
    int lengthOfLastWord(string s) {
        for(string word;std::istringstream is( s ); is >> word;)
        {
            std::cout << word << '\n';
        }
        return word.length();
    }
};