// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,size_t> lookup;
        for(auto num:nums){
            lookup[num]++;
        }
        auto pr = std::max_element(lookup.begin(), lookup.end(),
        [](const auto &x, const auto &y) {
                    return x.second < y.second;
        });
 
        return pr->first;
    }
};