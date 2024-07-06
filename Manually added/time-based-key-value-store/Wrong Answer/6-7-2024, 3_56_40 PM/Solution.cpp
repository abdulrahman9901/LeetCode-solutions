// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    map<int,map<string,string>> tmap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        tmap[timestamp][key] = value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp && tmap.find(timestamp)==tmap.end()){
            cout<<timestamp<<endl;
            timestamp--;
        }
        return tmap[timestamp][key];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */