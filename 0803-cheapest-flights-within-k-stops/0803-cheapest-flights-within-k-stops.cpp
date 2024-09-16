class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<long> prices(n,INT_MAX);
        vector<long> tempPrices;
        prices[src] = 0;
        for(int i=0;i<k+1;i++){
            tempPrices.assign(prices.begin(), prices.end());  
            for(auto flight : flights){
                if(tempPrices[flight[0]] == INT_MAX)
                    continue;
                tempPrices[flight[1]] = min(tempPrices[flight[1]] ,(prices[flight[0]] + flight[2]));
            }
            prices.assign(tempPrices.begin(), tempPrices.end());  
        }
        if(prices[dst] == INT_MAX)
            return -1;
        return prices[dst];
    }
};