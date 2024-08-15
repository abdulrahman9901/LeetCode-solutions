class KthLargest {
    priority_queue<int, vector<int>, greater<int> > pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto num:nums){
            if(pq.size() == k && pq.top() < num){
                pq.pop();
                pq.push(num);
            }else if (pq.size() < k ){
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size() < k){
            pq.push(val);
        }
        else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */