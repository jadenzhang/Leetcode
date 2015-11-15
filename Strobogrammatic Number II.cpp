class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> strobogs;
        if (n%2==1) {
            strobogs = {"0","1","8"};
            n--;
        }
        else strobogs = {""};
        
        vector<string> base = {"00","69","96","88","11"};
        while (n>0){
            n-=2;
            vector<string> temp;
            for (auto a:strobogs){
                for (int i= n==0? 1:0;i<base.size();i++){
                    temp.push_back(base[i].front()+a+base[i].back());
                }
            }
            strobogs = temp;
        }
        
        return strobogs;
    }
};
