// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> sortedArr;
        map<int,int>freqArr;
        vector<int> res;
        for(int i = 0 ; i < nums.size() ; ++i){
            freqArr[nums[i]]++;
        }
        for(auto m : freqArr)
            sortedArr.push_back(m);

        sort(sortedArr.begin(),sortedArr.end(),[](pair<int,int> a , pair<int,int> b)
        {
            return a.second > b.second;
        });
        while(k--)
            res.push_back(sortedArr[k].first);
        return res ;
    }
};