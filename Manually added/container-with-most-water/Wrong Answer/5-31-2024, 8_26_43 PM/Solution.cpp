// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> sortedHeights;
        int maxVal = 0 , st = 0;
        for(int i = 0 ; i < height.size() ; ++i){
            sortedHeights.push_back({height[i],i});
        }
        sort(sortedHeights.begin(),sortedHeights.end(),std::greater());
        maxVal = sortedHeights[1].first * abs(sortedHeights[1].second - sortedHeights[st].second);
        for(int i = 1 ; i < height.size() ; ++i){
            int temp ;
            while(abs(sortedHeights[i].second - sortedHeights[st].second) < abs(sortedHeights[i].second - sortedHeights[st+1].second)){
                st++;
                temp = sortedHeights[i].first * abs(sortedHeights[i].second - sortedHeights[st].second);

                if(maxVal < temp){
                    maxVal = temp;
                    cout<< temp <<endl;
                }
            }
        }
        
        return maxVal;
    }
};