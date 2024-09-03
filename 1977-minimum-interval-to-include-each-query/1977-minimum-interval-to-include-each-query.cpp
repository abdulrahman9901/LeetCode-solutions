class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> res(n,-1);
        vector<pair<int, int>> queryWithIndex(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (int i = 0; i < n; ++i) {
            queryWithIndex[i] = {queries[i], i};
        }

        sort(queryWithIndex.begin(), queryWithIndex.end());

        sort(intervals.begin(), intervals.end());

        sort(queries.begin(), queries.end());

        int length,j = 0;
        
        for(auto queryPair:queryWithIndex){
            auto query = queryPair.first;
            while(j < intervals.size() && query >= intervals[j][0]){
                length = (intervals[j][1] - intervals[j][0] + 1);
                minHeap.push({length, intervals[j][1]});
                j++;
            }
            while (!minHeap.empty() && minHeap.top().second < query) {
                minHeap.pop();
            }
            if(!minHeap.empty())
                res[queryPair.second]=minHeap.top().first;                
        }
        return res;
    }
};