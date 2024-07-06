// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());
        long left = 1 , right = maxVal , k , th=0 , res = maxVal;
        while(left <= right){
            th = 0 ;
            k = (right + left)/2;
            for(auto pile:piles){
                th+=ceil(double(pile)/k);
            }
            cout<<k<<" : "<<th<<" >> "<<left <<":"<< right<<endl;
            if(th > h){
                left = k + 1;
            }else if(th <= h) {
                res = min(res,k);
                right = k - 1; 
            }else{
                res = min(res,k);
                break;
            }
        }  
        return res;
    }
};