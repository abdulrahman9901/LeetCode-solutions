// https://leetcode.com/problems/lru-cache

class LRUCache {
    map<int, pair<int, int> > cache;
    int cap = 0 ;
    bool used[10001] = {false};
    int timestamp = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(used[key]){
            cache[key].second = timestamp ;
            timestamp++;
            cout<<key<<" "<<cache[key].first<< " " << timestamp <<endl;
            return cache[key].first;
        }else 
            return -1;
    }
    
    void put(int key, int value) {
        if(cap){
            cache[key] = pair<int,int>(value,timestamp);
            cap--;
        }else {
        if(used[key]) {
            cache[key] = pair<int,int>(value,timestamp); 
        }else {
        auto it = std::min_element(cache.begin(), cache.end(),
            [](const auto& l, const auto& r) { return l.second.second < r.second.second; });

        used[it->first] = false;
        cache.erase(it);

        cache[key] = pair<int,int>(value,timestamp);
        }
        }
        timestamp++;
        used[key] = true; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */