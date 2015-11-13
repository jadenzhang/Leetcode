class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int p = -1,start = 0;
        int len = INT_MIN;
        for (int i=1;i<s.size();i++){
            if (s[i]==s[i-1]) continue;
            
            if (p>=0 && s[p]!=s[i]){
                len = max(len, i-start);
                start = p + 1;
            }
            
            p = i-1;
        }
        
        return max(len,(int)s.size()-start);
    }
};
