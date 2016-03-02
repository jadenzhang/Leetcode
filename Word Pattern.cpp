class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char> stop;
        unordered_map<char,string> ptos;
        stringstream iss(str);
        string temp;
        int i;
        for (i=0;iss>>temp;i++){
            if (!stop.count(temp)){
                stop[temp] = pattern[i];
            }
            else if (stop[temp] != pattern[i]) return false;
            
            if (!ptos.count(pattern[i])){
                ptos[pattern[i]] = temp;
            }
            else if (ptos[pattern[i]] != temp) return false;
        }
        
        if (i != pattern.size()) return false;
        
        return true;
    }
};
