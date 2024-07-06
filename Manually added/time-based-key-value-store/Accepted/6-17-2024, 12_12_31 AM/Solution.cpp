// https://leetcode.com/problems/time-based-key-value-store

class Node {
    public:
    string key;
    string value;
    Node * next;
    Node * prev;
    Node(string key ,string value , Node * next = nullptr,Node * prev = nullptr) :key(key),value(value),next(next),prev(prev)
    {}
};
class TimeMap {
public:
    map<int,Node*> tMap ;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        tMap[timestamp] = new Node(key,value);
    }
    
    string get(string key, int timestamp) {
        auto it = tMap.lower_bound(timestamp);
        while(it == tMap.end() || it->first > timestamp || tMap[it->first]->key != key) {
            if(it == tMap.begin()){
                return "";
            }         
            --it;
        }
        return tMap[it->first]->value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */