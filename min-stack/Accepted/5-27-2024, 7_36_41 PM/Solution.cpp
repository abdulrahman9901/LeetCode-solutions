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
        cout<<"pushVal "<<val<<endl;
        if(val < minVal)
            minVal = val;
        stack.push_back({val,minVal});   
    }
    
    void pop() {
        cout<<"popVal "<<stack.back().first<<endl;
        stack.pop_back();
        if(stack.empty())   
            minVal = std::numeric_limits<long>::max();
        else
            minVal = stack.back().second;
    }
    
    int top() {
       cout<<"topVal "<<stack.back().first<<endl;
       return stack.back().first;
    }
    
    int getMin() {
        cout<<"minVal "<<minVal<<endl;
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