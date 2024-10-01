class Solution {
    int dfs(vector<int>& prices , map<pair<int,bool>,int> &dp ,int index  ,bool buying){
        if(index >= prices.size()){
            return 0;
        }
        
        if (dp.find({index, buying}) != dp.end()) {
            return dp[{index, buying}];  
        }

        int coolDown = dfs(prices,dp,index+1,buying);

        if(buying){
            int buy = dfs(prices,dp,index+1,!buying) - prices[index];
            dp[{index,buying}] = max(coolDown,buy);
        }else{
            int sell = dfs(prices,dp,index+2,!buying) + prices[index];
            dp[{index,buying}] = max(coolDown,sell);
        }
    return dp[{index,buying}] ;
    };   
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int,bool>,int> dp;
        return dfs(prices,dp,0,true);
    }
};