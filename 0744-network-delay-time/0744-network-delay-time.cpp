class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> adjList;
        map<int,bool> visited;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> > minHeap;
        int vCount = 0 ;
        for(int i = 0 ; i < times.size();++i){
            adjList[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        minHeap.push({0,k});

        while(!minHeap.empty()){

            auto [currentCost , node] = minHeap.top();

            minHeap.pop();  

            if(visited[node])continue;

            visited[node] = true;
            vCount++;
            
            if(vCount == n)return currentCost;

            for(auto [nei , weight] : adjList[node]){
                if(!visited[nei]){
                    minHeap.push({weight + currentCost,nei});
                }
            }
          
        }
        return -1;
    }
};