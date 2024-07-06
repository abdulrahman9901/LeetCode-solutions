// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int st , end , n = nums.size() ;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        auto temp = nums;
        temp.erase(std::unique(temp.begin(), temp.end()), temp.end());
        if(nums.size() <= 3){
            if(nums.size() == 3 && std::accumulate(nums.begin(), nums.end(), 0) == 0)
                return {nums};
            return res;
        }
        else if(temp.size() == 1 && temp[0]==0){
            return {{0,0,0}};
        }
        //else if (temp.size() == 3){
        //     int sum = accumulate(temp.begin(),temp.end(),0) ;
        //     if(sum)
        //         return res;
        //     return {temp};
        // }

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