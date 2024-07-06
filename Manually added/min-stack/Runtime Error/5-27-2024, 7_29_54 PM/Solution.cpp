// https://leetcode.com/problems/min-stack

class MinStack {
private:
    vector<pair<long, long>> stack;
    long minVal;
public:

    MinStack() {
       minVal = std::numeric_limits<long>::max();
    }
    
    void push(int val) {
        if(val < minVal)
            minVal = val;
        stack.push_back({val,minVal});   
    }
    
    void pop() {
        stack.pop_back();   
        minVal = stack.back().second;
    }
    
    int top() {
       return stack.back().first;
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */