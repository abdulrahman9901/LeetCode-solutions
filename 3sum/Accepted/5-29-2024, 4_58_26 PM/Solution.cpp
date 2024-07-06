// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int st , end , n = nums.size() ;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            st=i+1;end=n-1;
            while(st < end){
                if(nums[i] + nums[st] + nums[end] < 0 )
                    st++;
                else if(nums[i] + nums[st] + nums[end] > 0 )
                    end--;
                else if(nums[i] + nums[st] + nums[end] == 0){
                     s.insert({nums[i],nums[st],nums[end]});
                    st++;
                    end--;
                }
            }
            
        }

        for(auto triplets : s)
            res.push_back(triplets);
        return res;

        return res;
    }
};