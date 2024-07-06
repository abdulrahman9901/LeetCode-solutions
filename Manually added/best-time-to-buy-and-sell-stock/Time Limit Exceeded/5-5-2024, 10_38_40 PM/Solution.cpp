// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i = 0 ; i < prices.size();++i){     // buy day
            for(int j = i ; j < prices.size();++j){   //sell day
                maxProfit = max(maxProfit,prices[j]-prices[i]);
            }   
        }
        return maxProfit ;
    }
};