class Solution {
public:
    double myPow(double x, int n) {
        bool neg= n<0? true:false;
        n=abs(n);
        double res=1;
        for (int i=31;i>=0;i--){
            res*=res;
            if(n & (1<<i)){
                res*=x;
            }
        }
        
        if (neg) return 1/res;
        return res;
    }
};
