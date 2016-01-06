class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i1 = 0, i2 = 0, i3 = 0;
        while (res.size()<n){
            int u2 = res[i1]*2, u3 = res[i2]*3, u5 = res[i3]*5;
            int un = min(u2,min(u3,u5));
            if (un == u2) i1++;
            if (un == u3) i2++;
            if (un == u5) i3++;
            res.push_back(un);
        }
        return res[n-1];
    }
};
