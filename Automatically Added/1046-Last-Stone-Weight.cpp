class Solution {

public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int x , y;
        for(auto stone:stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            y = pq.top();pq.pop();
            x = pq.top();pq.pop();
            if(y > x)
                pq.push(y-x);
        }
        if(pq.empty())
            return 0;
        else 
            return pq.top();
    }
};