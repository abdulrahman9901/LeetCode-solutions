// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
    if (strs.empty()) {
        return res; // Return an error code to indicate an empty vector.
    }

    std::string shortestString = strs[0]; // Initialize with the first string
    for (const std::string& str : strs) {
        if (str.length() < shortestString.length()) {
            shortestString = str;
        }
    }
    for(size_t j = 0 ; j < shortestString.length() ; j++){
        for(size_t i = 0 ; i < strs.size() ; i++){
            if(strs[i][j] != shortestString[j] )
                return "";
            else 
                res +=shortestString[j];
        }
    }
        return res;
    }
};