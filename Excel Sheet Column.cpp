class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n){
            int r=n%26;
            n/=26;
            if (r==0){
                result+='Z';
                n--;
            }
            else{
                result+=('A'+r-1);
            }
        }
        
        string newresult;
        for (int i=result.size()-1;i>=0;i--) newresult+=result[i];
        return newresult;
    }
};
