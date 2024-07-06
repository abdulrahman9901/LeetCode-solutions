// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum=0;
        for (auto v :triangle){
            sum+=(*min_element(v.begin(), v.end()));
        }
        return sum;
    }
};