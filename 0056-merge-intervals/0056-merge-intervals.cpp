class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
       sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
        return a[0] < b[0];
        });

        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size();++i){
            if(intervals[i][0] > res.back()[1]){
                res.push_back(intervals[i]);
            }else{
                while(i < intervals.size() && res.back()[1] >= intervals[i][0]){
                    cout<<res.back()[1] << " "<< intervals[i][0]<<endl;
                    res.back()[0] = min(intervals[i][0],res.back()[0]);
                    res.back()[1] = max(intervals[i][1],res.back()[1]);
                    i++;
                }
                i--;
            }
        }
    return res;
    }
};