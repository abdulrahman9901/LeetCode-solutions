// https://leetcode.com/problems/k-th-smallest-prime-fraction

class Solution {
public:
    vector<int>kthSmallestPrimeFraction(vector<int>& arr, int k) {
        std::vector<std::pair<std::pair<int, int>, double>> fractions ;
        //map<pair<int,int>,double>fractions;
        for(int j=1 ; j < arr.size();j++){
            for(int i=0 ; i < j ;i++){
                double temp =double(arr[i])/arr[j];
                    // fractions[{arr[i],arr[j]}] = temp;
                    fractions.push_back({{arr[i],arr[j]},temp});
            }
        }

        sort(fractions.begin(),fractions.end(),[](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });
        auto it = fractions.begin();
        std::advance(it, k-1 ); // Move the iterator to the kth element
        return {it->first.first,it->first.second};
    }
};