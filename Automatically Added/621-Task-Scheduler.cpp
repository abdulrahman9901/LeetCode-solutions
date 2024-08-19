
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> taskCount;
        priority_queue<int> readyQueue;
        queue<pair<int,int>> waitingQueue;
        int time=0;
        for(char task:tasks){
            taskCount[task]+=1;
        }
        for(auto task:taskCount){
            readyQueue.push(task.second);
        }
        while(!readyQueue.empty() || !waitingQueue.empty()){
            if(!waitingQueue.empty() && waitingQueue.front().second <= time ){
                readyQueue.push(waitingQueue.front().first);
                waitingQueue.pop();
            }
            if(!readyQueue.empty()){
                if(readyQueue.top()-1 > 0)
                    waitingQueue.push(pair<int,int>(readyQueue.top()-1,time+n+1));
                readyQueue.pop();
            }
            time++;
        }
    return time;
    }
};