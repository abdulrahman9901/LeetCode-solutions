// https://leetcode.com/problems/car-fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = speed.size();
        stack<double> fleets;
        vector<pair<int,int>> cars;

        while(true){
            for(int i=0 ;i < len ; ++i){
                cars.push_back({position[i],speed[i]});
            }
            sort(cars.begin(),cars.end(),std::greater());

            for(auto car:cars){
               double time = (target - car.first)/car.second ;
                if(!fleets.empty()){
                    if(time > fleets.top())
                        fleets.push(time);
                }else {
                    fleets.push(time);
                }
            }
            return fleets.size();
        }
    }
};