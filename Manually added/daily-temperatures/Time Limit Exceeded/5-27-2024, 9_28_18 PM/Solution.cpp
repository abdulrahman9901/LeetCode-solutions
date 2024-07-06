// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        size_t len = temperatures.size();
        vector<int> answer (len,0);
        for(int i = 0 ; i<len ;++i){
            for(int j =i+1;j<len;j++){
                if(temperatures[j] > temperatures[i]){
                    answer[i]=j-i;
                    break;
                }
            }
        }
        return answer;
    }
};