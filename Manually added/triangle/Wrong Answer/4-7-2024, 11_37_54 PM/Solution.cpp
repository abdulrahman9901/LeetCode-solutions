// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        size_t sum= 0 , pos = 0 , len;
        for (auto v :triangle){
            len=v.size();
            if(pos+1 >= len){
                sum+=v[pos];
                continue;
            }
           if( v[pos] < v[pos+1])
                sum+=v[pos];
            else
            {
                sum+=v[pos+1]; 
                pos+=1;
            }
        }
        return sum;
    }
};