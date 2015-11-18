class Solution {
public:
    void reverseWords(string &s) {
        if (s.size()==0) return;
        int fast = 0, slow = 0, start = 0;
        int wordcount = 0;
        while (true){
            while (s[fast] == ' ') fast++;
            if (fast == s.size()) break;
            if (wordcount) s[slow++] = ' ';
            start = slow;
            while (s[fast]!=' '&& fast<s.size()){
                s[slow] = s[fast];
                slow++;
                fast++;
            }
            reverseHelper(s,start,slow-1);
            wordcount++;
        }
        
        s.resize(slow);
        reverseHelper(s,0,slow-1);
    }
    
    void reverseHelper(string &s, int i, int j){
        while (i<j){
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
};
