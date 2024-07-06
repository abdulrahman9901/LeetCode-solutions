// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t len = temperatures.size();
        stack<int> indx;
        vector<int> answer (len,0);
        indx.push(0);
        for(int i = 1 ; i<len ;++i){
            while(!indx.empty() && temperatures[i] > temperatures[indx.top()]){
                answer[indx.top()]=i-indx.top();
                indx.pop();
            }
            indx.push(i);
        }
        return answer;
    }
};