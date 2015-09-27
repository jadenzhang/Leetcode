class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="") return true;
        int begin=0;
        int end=s.size()-1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (begin<end){
            while (begin<end && !isAlpha(s[begin])) begin++;
            while (begin<end && !isAlpha(s[end])) end--;
            if (s[begin]!=s[end]) break;
            begin++;
            end--;
        }
        
        if (begin>=end) return true;
        else return false;
    }
    
    bool isAlpha(char c){
        if (c<='z' && c>='a') return true;
        if (c<='9' && c>='0') return true;
        return false;
    }
};
