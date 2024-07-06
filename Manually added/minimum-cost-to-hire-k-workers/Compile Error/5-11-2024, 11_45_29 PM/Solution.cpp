// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> wageQualityRatio ;
        priority_queue WorkGroup;
        int totalQuality;
        
        for(int i=0 ;i<quality.size();++i){
            wageQualityRatio.push_back({double(wage[i])/quality[i],quality[i]});
        }
        sort(wageQualityRatio.begin(),wageQualityRatio.end());
        for(int i=0 ;i<quality.size();++i){
            totalQuality+=wageQualityRatio[i].second;
            WorkGroup.push(wageQualityRatio[i].second);
        }
            return 105;
    }
};