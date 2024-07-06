// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int currentPrice ;
        int buyPrice = prices[0];
        for(int i = 1 ; i < prices.size();++i){
            currentPrice = prices[i];
            if(currentPrice < buyPrice){
                buyPrice=currentPrice;
            }
                maxProfit = max(maxProfit,currentPrice - buyPrice); 
        }
        return maxProfit ;
    }
};