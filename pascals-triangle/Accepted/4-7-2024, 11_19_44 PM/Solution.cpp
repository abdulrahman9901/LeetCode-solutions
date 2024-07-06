// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0){
           return result;
        }else {
            result.push_back({1});
            for(int i = 1 ; i < numRows ; ++i){
                vector<int> temp(i+1,0);
                for(int j = 0 ; j < i+1 ; ++j){
                    if(j<i)
                        temp[j] = result[i-1][j];
                    if(j-1>=0)
                            temp[j]+=result[i-1][j-1];
                }
                result.push_back(temp);
            }
        }
        return result;
    }
};