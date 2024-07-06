// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result={1};
        if(rowIndex == 0){
           return result;
        }else {
            for(int i = 1 ; i <= rowIndex ; ++i){
                vector<int> temp(i+1,0);
                for(int j = 0 ; j < i+1 ; ++j){
                    if(j<i)
                        temp[j] = result[j];
                    if(j-1>=0)
                            temp[j]+=result[j-1];
                }
                result = temp;
            }
        }
        return result;
    }
};