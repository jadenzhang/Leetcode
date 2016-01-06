class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(1,1);
        vector<int> index(primes.size(),0);
        while (res.size()<n){
            int m = INT_MAX, mindex;
            for (int i=0;i<primes.size();i++){
                int temp = primes[i] * res[index[i]];
                if (temp<m){
                    m = temp;
                    mindex = i;
                } 
            }
            index[mindex]++;
            if (m!=res[res.size()-1]) res.push_back(m);
        }
        
        return res[n-1];
    }
};
