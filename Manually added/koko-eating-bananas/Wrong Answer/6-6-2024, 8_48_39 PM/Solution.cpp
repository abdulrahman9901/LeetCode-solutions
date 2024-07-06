// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());
        int left = 1 , right = maxVal , k , th=0;
        while(left <= right){
            th = 0 ;
            k = (right + left)/2;
            for(auto pile:piles){
                th+=ceil(double(pile)/k);
            }
            cout<<k<<" : "<<th<<" >> "<<left <<":"<< right<<endl;
            if(th > h){
                left = k + 1;
            }else if(th < h) {
                right = k - 1; 
            }else{
                break;
            }
        }  
        return k;
    }
};