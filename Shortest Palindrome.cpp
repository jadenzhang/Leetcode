class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size()<=1) return s;
        string ret;
        int mid = (s.size()-1)/2;
        for (int i=mid;i>=0;i--){
            if (s[i]==s[i+1]){
                ret = check(s,i,i+1);
                if (ret!="") return ret;
            }
            ret = check(s,i,i);
            if (ret!="") return ret;
        }
    }
    
    string check(string s, int left, int right){
        int i=1;
        for (;left-i>=0 && right+i<s.size();i++){
            if (s[left-i] != s[right+i]) break;
        }
        if (left-i>=0) return "";
        string temp = s.substr(right+i,s.size()-right-i+1);
        reverse(temp.begin(), temp.end());
        return temp+s;
    }
};// 超时
