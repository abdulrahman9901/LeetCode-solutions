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
        for(int i = 1 ; i < height.size() ; ++i){
            if(abs(sortedHeights[i].second - sortedHeights[st].second) < abs(sortedHeights[i].second - sortedHeights[st+1].second)){
                cout<< st <<" : "<< i <<endl;
                st++;
            }
            int temp = sortedHeights[i].first * abs(sortedHeights[i].second - sortedHeights[st].second);
            if(maxVal < temp){
                //cout<<sortedHeights[i].first <<" : "<< abs(sortedHeights[i].second - sortedHeights[st].second)<<endl;
                maxVal = temp;
            }
        }
        
        return maxVal;
    }
};