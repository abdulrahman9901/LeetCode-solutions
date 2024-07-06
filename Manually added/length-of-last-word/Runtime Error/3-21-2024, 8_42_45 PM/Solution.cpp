// https://leetcode.com/problems/length-of-last-word

#include <cstring>  
class Solution {
public:
    int lengthOfLastWord(string s) {
        // string word;
        // for(std::istringstream is( s ); is >> word;)
        // {
        //     std::cout << word << '\n';
        // }
        // return word.length();
        size_t len=0;
        for(size_t i =s.length()-1 ; i >=0 ; i--){
            if(s[i] == ' '){
                if(len)
                    break;
            }else {
                len++;
            }
        }
        return len;
    }
};