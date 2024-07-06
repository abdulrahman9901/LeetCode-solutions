// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result{{1},{1,1}};
        if(numRows == 1){
           return {{1}};
        }else {
            for(size_t i = 2 ; i < numRows ; ++i){
                vector<int> temp(i+1,0);
                for(size_t j = 0 ; j < i+1 ; ++j){
                    
                    if(j <= int(i/2)){
                         + ;
                    }
                }
                result,push_back(temp);
            }
        }
        return result;
    }
};