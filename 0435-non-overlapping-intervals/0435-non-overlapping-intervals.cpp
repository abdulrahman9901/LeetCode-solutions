class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       vector<vector<int>> res;
       int count = 0;
      sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
            return a[1] < b[1];    
        });

        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();++i){
            if(intervals[i][0] >= res.back()[1]){
                res.push_back(intervals[i]);
            }else{
                while(i < intervals.size() && res.back()[1] > intervals[i][0]){
                    count++;
                    i++;
                }
                i--;
            }
        }
    return count;
    }
};