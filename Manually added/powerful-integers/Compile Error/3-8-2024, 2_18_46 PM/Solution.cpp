// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> powerful ;
        size_t i =0 , j=0;
        int Xval = pow(x,i) , Yval;
        while(Xval < bound){
            
            Yval = pow(y,j)
            while(Yval+Xval < bound){
                powerful,push(Yval+Xval);
                j++;
                Yval = pow(y,j)
            }
            i++;
            Xval = pow(x,i) 
        }
    }
};