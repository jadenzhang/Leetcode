class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> match(n+1,vector<bool>(m+1,false));
        match[0][0]=true;
        for (int i=1;i<=m;i++){
            if (p[i-1]=='*'){
                match[0][i]=match[0][i-2];
            }
        }
        
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (p[j-1]!='*'){
                    match[i][j]=match[i-1][j-1] && (p[j-1]=='.' ? true:s[i-1]==p[j-1]);
                }
                else{
                    match[i][j]=match[i][j-2] ||(match[i-1][j] && ((p[j-2]=='.')? true:p[j-2]==s[i-1]));
                }
            }
        }
        return match[n][m];
    }
};
