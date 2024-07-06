// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
    static int euclideanDistance(vector<int> point){
        return sqrt(pow(point[0],2) + pow(point[1],2));
    }
    static bool compare(vector<int>  a, vector<int> b) {
        return euclideanDistance(a) < euclideanDistance(b) ;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),compare);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};