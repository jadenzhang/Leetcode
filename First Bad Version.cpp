class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl=haystack.size(), nl=needle.size();
        int i=0,j=0;
        int start;
        while (i<hl && j<nl){
            if (haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                i=i-j+1;
                j=0;
            }
        }
        
        if (j==nl) return i-j;
        else return -1;
        
    }
};
