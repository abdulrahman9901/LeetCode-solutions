class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> map;
        vector<string> res;
        vector<pair<string,int>> vm;
        for(string word:words){
            map[word]++;
        }
        for(auto m:map){
            vm.push_back(m);
        }
        sort(vm.begin(),vm.end(),[](auto a, auto b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        for(int i = 0 ; i < k ;++i){
            res.push_back(vm[i].first);
        }
        return res;
    }
};