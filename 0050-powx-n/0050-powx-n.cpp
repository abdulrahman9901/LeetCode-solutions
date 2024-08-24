class Solution {
public:
    double myPow(double x, int n) {
        double res = x;
        long i;
        if(n == 0 )
            return 1;
        if(x == 0)
            return 0;
        if(abs(x)==1){
            if(x == 1 || n%2==0)
                return 1;
            return -1;
        }
        for(i = 2 ; i < abs(n) ; i*=2){
            res*=res;
        } 
        for(i/=2;i < abs(n);++i){
            res*=x;
        }
        res = n > 0 ? res : 1/res;
        return res;
    }
};