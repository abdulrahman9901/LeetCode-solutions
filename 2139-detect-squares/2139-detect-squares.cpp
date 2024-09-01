class DetectSquares {
    map<pair<int, int>, int> PointsFreq;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        PointsFreq[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1];
        
        for (auto& [pt, freq] : PointsFreq) {
            int x3 = pt.first, y3 = pt.second;
            if (abs(x1 - x3) != abs(y1 - y3) || x1 == x3 || y1 == y3) {
                continue;
            }
            
            res += freq * PointsFreq[{x1, y3}] * PointsFreq[{x3, y1}];
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */