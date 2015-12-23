class Solution {
public:
    int bulbSwitch(int n) {
        /*if (n==1) return 1;
        vector<int> bulbs(n,1);
        for (int i=2;i<=n;i++){
            int cur = -1;
            while (cur+i < n){
                if (bulbs[cur+i]) bulbs[cur+i]=0;
                else bulbs[cur+i] = 1;
                cur = cur+i;
            }
        }
        
        int count;
        for (auto a:bulbs) if (a) count++;
        return count;*/
        
        return sqrt(n);
        
        
        
    }
};
