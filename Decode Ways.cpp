class Solution {
public:
    int numDecodings(string s) {
        if (!s.size()|| s[0]>'9'||s[0]<'1') return 0;
        vector<int> ways(s.size()+1,0);
        ways[0]=ways[1]=1;
        for (int i=1;i<s.size();i++){
            int num=(s[i-1]-'0')*10+s[i]-'0';
            if (num<=26 && num>9) ways[i+1]+=ways[i-1];
            if (s[i] !='0') ways[i+1]+=ways[i];
            if (ways[i+1]==0) return 0;
        }
        
        return ways[s.size()];
    }
};
