// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int st , end , n = nums.size() ;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        cout<<nums[0]<<" : "<<nums[1]<<endl;
        for(int i = 0 ; i < n ; i++){
            st=0;end=n-1;
            while(nums[st] <= 0 && st < end ){
            cout<<"at i = "<< i<<" : "<<nums[i] << nums[st] << nums[end] <<endl;
                if(st == i ||  
                nums[i] + nums[st] + nums[end] < 0 )
                    st++;
                else if(end == i ||
                  nums[i] + nums[st] + nums[end] > 0 )
                    end--;
                else if(nums[i] + nums[st] + nums[end] == 0){
                    res.push_back({nums[i],nums[st],nums[end]});
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