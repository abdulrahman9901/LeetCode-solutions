// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // sort(heights.begin(),heights.end(),greater<int>());
        stack<int> st;
        int minVal , maxVal = 0;
        for(auto h:heights){
            if(h == 0)
                continue;
            if(st.empty()){
                minVal = h;
                st.push(h);
                maxVal =  minVal ;
            }else {
                if(h > st.top()){
                    minVal = st.top();
                    st=stack<int>();
                    st.push(minVal);
                    st.push(h);
                    maxVal = max(maxVal , int(st.size() * minVal));
                }else {
                    st.push(h);
                    minVal = min(h,minVal);
                    maxVal = max(maxVal , int(st.size() * minVal));
                }
            }
        }
        return maxVal;
    }
};