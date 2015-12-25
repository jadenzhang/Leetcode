class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> dic(n);
        for (int i=0;i<n;i++){
            int bit = 0;
            for (auto word:words[i]){
                bit = bit | 1<<(word-'a');
            }
            dic[i]=bit;
        }
        
        int m = 0;
        for (int i=0;i<n-1;i++){
            if (words[i].length() * words[i].length() < m) continue;
            for (int j=i+1;j<n;j++){
                if (dic[i] & dic[j]) continue;
                m = max(m,int(words[i].size() * words[j].size()));
                break;
            }
        }
        
        return m;
    }
    
    static bool compare(string a, string b){
        return a.size()>b.size();
    }
};
