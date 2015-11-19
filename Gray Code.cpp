class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if (n==0) return ret;
        ret.push_back(1);
        if (n==1) return ret;
        for (int i=2;i<=n;i++){
            for (int j=ret.size()-1;j>=0;j--) ret.push_back((1<<(i-1)) + ret[j]);
        }
        
        return ret;
    }
};
