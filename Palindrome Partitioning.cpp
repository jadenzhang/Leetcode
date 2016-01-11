class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ret;
        vector<string> sol;
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                dp[j][i] = (s[i]==s[j]) && (i-j==1 || dp[j+1][i-1]);
            }
            dp[i][i] = 1;
        }
        
        FindPartitions(dp,ret,0,sol,s);
        return ret;
        
    }
    
    void FindPartitions(vector<vector<int>> dp, vector<vector<string>> &ret, int start, vector<string> sol, string s){
        if (start == s.size()){
            ret.push_back(sol);
            return;
        }
        for (int i=start;i<s.size();i++){
            int len = i-start+1;
            if (dp[start][i]){
                sol.push_back(s.substr(start,len));
                FindPartitions(dp,ret,i+1,sol,s);
                sol.pop_back();
            }
        }
    }
};
