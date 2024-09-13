class Solution {
    int calcDist(pair<int,int> pt1 ,pair<int,int> pt2){
        return abs(pt1.first - pt2.first) + abs(pt1.second - pt2.second);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>,vector<pair<int,int>>> adjList;
        map<pair<int,int>,bool> visited;
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> ,greater<> > minHeap;
        int cost = 0 , visitedCount = 0;
        for(int i = 0 ; i < points.size();++i){
            pair<int,int> currPoint  = {points[i][0],points[i][1]};
            for(int j = 0 ; j < points.size() ; ++j){
                if(i == j)
                    continue;
                adjList[currPoint].push_back({points[j][0],points[j][1]});
            }
        }
        minHeap.push({0,{points[0][0],points[0][1]}});
        while(!minHeap.empty()){
            auto top = minHeap.top();
            minHeap.pop();
            if(visited[top.second])
                continue;
            if(visitedCount == points.size())
                break;
            cost+=top.first;
            visited[top.second] = true;
            visitedCount++;
            for(auto nei : adjList[top.second]){
                minHeap.push({calcDist(top.second,nei),nei});
            }
        }
        return cost;
    }
};