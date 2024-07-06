// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int maxLeft[n] , maxRight[n] , trappedWater = 0;
        maxLeft[0]=height[0];
        maxRight[n-1]=height[n-1];
        for(int i = 1 ; i< n ; ++i){
           maxLeft[i] = max(maxLeft[i-1] , height[i-1]);
           maxRight[n-i-1] = max(maxRight[n-i] , height[n-i]);
        }
        for(int i = 0 ; i< n ; ++i){
        trappedWater += min(maxLeft[i],maxRight[i]) - height[i] > 0 ?
            min(maxLeft[i],maxRight[i]) - height[i] : 0 ;
        }
        return trappedWater ;
    }
};