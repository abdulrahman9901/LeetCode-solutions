// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    bool add = false ;
    if (strs.empty()) {
        return ""; // Return an error code to indicate an empty vector.
    }

    std::string shortestString = strs[0] , result = "";

    for (const std::string& str : strs) {
        if (str.length() < shortestString.length()) {
            shortestString = str;
        }
    }
    for(size_t j = 0 ; j < shortestString.length() ; j++){
        add = true ;
        for(size_t i = 0 ; i < strs.size() ; i++){
            if(strs[i][j] != shortestString[j] ){
                add = false;
                break;
            }
        }
        if(add == false)
            break;
        else {
            add == false;
            result +=shortestString[j];
        }
    }
        return result;
    }
};