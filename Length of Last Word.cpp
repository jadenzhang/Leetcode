class Solution {
public:
    int lengthOfLastWord(string s) {
        int Curlen = 0, Lastlen = 0;
        for (int i=0; i<s.size();i++){
            if (isalpha(s[i])) Curlen++;
            else if (Curlen != 0) {
                Lastlen = Curlen;
                Curlen = 0;
            }
        }
        
        return Curlen == 0? Lastlen:Curlen;
    }
};
