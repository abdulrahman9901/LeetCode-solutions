// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> powerful ;
        size_t i =0 , j=0;
        int Xval = pow(x,i) , Yval;
        while(Xval < bound){
            j=0;
            Yval = pow(y,j);
            while(Yval+Xval <= bound){
            if (find(powerful.begin(),powerful.end(),Yval+Xval) == powerful.end()) 
                    powerful.push_back(Yval+Xval);
                j++;
                Yval = pow(y,j);
                if(Yval==1)
                    break;
            }
            i++;
            Xval = pow(x,i) ;
            if(Xval==1)
                break;
        }
        return powerful;
    }
};