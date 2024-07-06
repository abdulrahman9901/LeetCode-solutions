// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int st , end , n = nums.size() ;
        vector<pair<int,int>> indexMap(n,{0,0});
        vector<vector<int>> res;
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            indexMap[i]={i,nums[i]};
        }
        sort(indexMap.begin(),indexMap.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second < b.second;
        });
        cout<<indexMap[0].first<<" : "<<indexMap[0].second<<endl;
        for(int i = 0 ; i < n ; i++){
            st=0;end=n-1;
            while(st < end && indexMap[i].second < 0){
            cout<<"at i = "<< i<<" : "<<indexMap[i].second << indexMap[st].second << indexMap[end].second <<endl;
                if(indexMap[st].first == indexMap[i].first ||  
                indexMap[i].second + indexMap[st].second + indexMap[end].second < 0 )
                    st++;
                else if(indexMap[end].first ==  indexMap[i].first ||
                  indexMap[i].second + indexMap[st].second + indexMap[end].second > 0 )
                    end--;
                else if(indexMap[i].second + indexMap[st].second + indexMap[end].second == 0){
                    res.push_back({indexMap[i].second,indexMap[st].second,indexMap[end].second});
                   st++;
                    end--;
                }
            }
            
        }

        for (auto& v : res) {
            std::sort(v.begin(), v.end());
        }

        std::sort(res.begin(), res.end());

        auto last = std::unique(res.begin(), res.end());
        res.erase(last, res.end());    

        return res;
    }
};