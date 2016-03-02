class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int A = 0;
        for (int i=0;i<n;i++){
            if (secret[i]==guess[i]) A++;
        }
        
        int B = 0;
        unordered_map<char,int> m;
        for (auto c:secret) m[c]++;
        for (auto c:guess){
            if(m[c]>0){
                B++;
                m[c]--;
            }
        }
        
        return to_string(A)+"A"+to_string(B-A)+"B";
    }
};
