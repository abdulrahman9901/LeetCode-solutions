class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        
        maxHeap.push(num);

        minHeap.push(maxHeap.top());

        maxHeap.pop();

        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        size++;
        
    }
    
    double findMedian() {
        if(size%2==0){
            return (minHeap.top() + maxHeap.top())/2.0;
        }else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */