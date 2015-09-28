class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.size();
        int len2=version2.size();
        
        for (int i=0,j=0;i<len1 || j<len2;i++,j++){
            
            int sum1=0;
            while(i<len1 && version1[i]!='.'){
                sum1 = sum1*10+version1[i]-'0';
                i++;
            } 
            
            int sum2=0;
            while(j<len2 && version2[j]!='.'){
                sum2 = sum2*10+version2[j]-'0';
                j++;
            }
            
            if (sum1>sum2) return 1;
            else if (sum1<sum2) return -1;
        }
        
        return 0;
    }
};
