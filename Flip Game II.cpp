class Solution {
public:
    bool canWin(string s) {
        if (s=="") return false;
        return play(s);
    }
private:
    bool play(string s){
        for (int i=1;i<s.length();i++){
            if (s[i]==s[i-1] && s[i]=='+'){
                s[i]=s[i-1]='-';
                bool win = !play(s);
                s[i]=s[i-1]='+';
                if (win) return true;
            }
        }
        
        return false;
    }
};
