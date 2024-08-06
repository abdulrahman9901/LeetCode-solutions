class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i = cost.size()-2, sum=0;
        while(i >= 0){
            int a = cost[i+1];
            int b = i+2 >= cost.size() ? 0 : cost[i+2];
            if(a >= b){
                cost[i] +=b;
            }else{
                cost[i] +=a;
            }
            i--;
        }
        return min(cost[0],cost[1]);
    }
};