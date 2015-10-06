class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> map;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i]) == map.end()) map[s[i]]=t[i];
            else if (map[s[i]] != t[i]) return false;
        }
        map.clear();
        for(int i=0;i<s.length();i++){
            if(map.find(t[i]) == map.end()) map[t[i]]=s[i];
            else if (map[t[i]] != s[i]) return false;
        }
        
        return true;
    }
};
