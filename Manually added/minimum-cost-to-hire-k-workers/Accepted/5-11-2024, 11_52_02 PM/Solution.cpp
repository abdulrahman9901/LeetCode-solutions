// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> wageQualityRatio ;
        priority_queue<int> WorkGroup;
        int totalQuality = 0;
        double minCost = DBL_MAX;
        for(int i=0 ;i<quality.size();++i){
            wageQualityRatio.push_back({double(wage[i])/quality[i],quality[i]});
        }
        sort(wageQualityRatio.begin(),wageQualityRatio.end());
        for(int i=0 ;i< quality.size() ;++i){
            totalQuality+= wageQualityRatio[i].second;
            double ratio = wageQualityRatio[i].first;

            WorkGroup.push(wageQualityRatio[i].second);

            if(WorkGroup.size() > k){
                totalQuality-=WorkGroup.top();
                WorkGroup.pop();
            }
            
            if(WorkGroup.size() == k){
                minCost = min(minCost, totalQuality * ratio);
            }
        }
        return minCost;
    }
};