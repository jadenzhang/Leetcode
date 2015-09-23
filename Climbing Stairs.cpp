class Solution {
public:
    int climbStairs(int n) {
        int s1=1, s2=2;
        if (n==1) return s1;
        if (n==2) return s2;
        int sn;
        for (int i=3;i<=n;i++){
            sn = s1 + s2;
            s1 = s2;
            s2 = sn;
        }
        
        return sn;
    }
};
