class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int p1=-1,p2=-1;
        int dis = INT_MAX;
        bool flag = true;
        for (int i=0;i<words.size();i++){
            if (words[i]==word1 && flag){
                p1=i;
                if (word1==word2) flag = false;
            }
            else if (words[i]==word2){
                p2=i;
                if (word1==word2) flag = true;
            } 
            
            if (p1!=-1 && p2!=-1) dis = min(dis,abs(p1-p2));
        }
        
        return dis;
    }
};
