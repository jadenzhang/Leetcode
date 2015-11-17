class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        dac(num,target,0,0,"",ret);
        return ret;
    }
    
    void dac(string num, long target, long last, long CurNum, string sol, vector<string> &ret){
        if (target == CurNum && num.size()==0){
            ret.push_back(sol);
            return;
        }
        
        for (int i=1;i<=num.size();i++){
            string cur = num.substr(0,i);
            if (cur.size()>1 && cur[0]=='0') return;
            string next = num.substr(i);
            if (sol.size()==0){
                dac(next,target,stoll(cur),stoll(cur),sol+cur,ret);
            }
            else{
                dac(next,target,stoll(cur),CurNum+stoll(cur),sol+"+"+cur,ret);
                dac(next,target,-stoll(cur),CurNum-stoll(cur),sol+"-"+cur,ret);
                dac(next,target,stoll(cur)*last,(CurNum-last) + last * stoll(cur),sol+"*"+cur,ret);
            }
        }
    }
};
