class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0, start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += (gas[i] - cost[i]);
            
            if(currentGas < 0){
                currentGas=0;
                start = i+1;
            }
        }
        if(totalGas  < totalCost) return -1;
    
        return start;
    }
};