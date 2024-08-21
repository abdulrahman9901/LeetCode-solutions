class Solution {
public:
    bool isHappy(int n) {
        do{
            int res = 0;
            while(n){
                res += pow(n%10,2);
                n/=10;
            }
            cout<<res<<endl;
            n = res;
        }while(n>4);

        return n == 1;
    }
};