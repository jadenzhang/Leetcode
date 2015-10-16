class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> ht;
        
        for (int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            ht[key].push_back(strs[i]);
        }
        
        for (unordered_map<string,vector<string>> :: iterator it=ht.begin();it!=ht.end();it++){
            sort(it->second.begin(),it->second.end());
            res.push_back(it->second);
        }
        
        return res;
    }
};
