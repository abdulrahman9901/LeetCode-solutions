// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> sortedHeights;
        int maxVal = 0;
        for(int i = 0 ; i < height.size() ; ++i){
            sortedHeights.push_back({height[i],i});
        }
        sort(sortedHeights.begin(),sortedHeights.end(),std::greater());
        for(int i = 1 ; i < height.size() ; ++i){
            int temp = sortedHeights[i].first * abs(sortedHeights[i].second - sortedHeights[i-1].second);
            if(maxVal < temp){
                maxVal = temp;
            }
        }
        
        return maxVal;
    }
};