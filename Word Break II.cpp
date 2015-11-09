class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        if (s.size()==0) return ret;
        string sol;
        vector<bool> pos(s.size()+1,true);
        dfs(0,ret,sol,pos,s,wordDict);
        return ret;
    }
    
    void dfs(int start, vector<string> &ret, string &sol, vector<bool> &pos, string s, unordered_set<string> &wordDict){
        if (start == s.size()){
            ret.push_back(sol.substr(0,sol.size()-1));
            return;
        }
        string piece;
        for (int i=start;i<s.size();i++){
            piece.push_back(s[i]);
            if (wordDict.count(piece) && pos[i+1]){
                int before = ret.size();
                sol.append(piece).append(" ");
                dfs(i+1,ret,sol,pos,s,wordDict);
                if (ret.size()==before) pos[i+1]=false;
                sol.resize(sol.size()-piece.size()-1);
            }
        }
    }
};
