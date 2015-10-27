class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> map(256,0);
        for (auto a:s){
            map[a]++;
        }
        
        int odd;
        for (auto a:map){
            if(a%2!=0) odd++;
        }
        
        return odd>1? false:true;
    }
};
