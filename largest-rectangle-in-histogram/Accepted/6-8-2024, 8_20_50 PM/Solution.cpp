// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxVal = 0;
        int len = heights.size();
        st.push({0,heights[0]});
        for(int i = 1 ; i <len;++i){
            if(heights[i] > st.top().second){
                st.push({i,heights[i]});
            }else{
                int s = i;
                while(!st.empty() && st.top().second > heights[i]){
                    if(maxVal < st.top().second * (i - st.top().first)){
                        maxVal = st.top().second * (i - st.top().first);
                    }
                    s = st.top().first;
                    st.pop();
                }
                st.push({s,heights[i]});
            }

        }
        while(!st.empty()){
            if(maxVal < st.top().second * (len - st.top().first)){
                maxVal = st.top().second * (len - st.top().first);
            }
            st.pop();
        }
        
        return maxVal;
    }
};