class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 )
            return 1;
        if(x == 0)
            return 0;
        if(abs(x)==1){
            if(x == 1 || n%2==0)
                return 1;
            return -1;
        }
        double res = x;
        long i;
        for(i = 2 ; i < abs(n) ; i*=2){
            res*=res;
            cout<<res<<" at i = "<<i<<endl;
        }
        cout<<res<<" at i = "<<i<<endl;
        i/=2;
        while(i < abs(n)){
            res*=x;
            i++;
        }
        if(n > 0)
            return res;
        else 
            return 1/res;
    }
};