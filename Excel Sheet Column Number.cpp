class Solution {
public:
    int titleToNumber(string s) {
        int len=s.size();
        int sum=0;
        for (int i=len-1;i>=0;i--){
            sum+=(s[i]-'@')*pow(26,len-1-i);
        }
        return sum;
    }
};
