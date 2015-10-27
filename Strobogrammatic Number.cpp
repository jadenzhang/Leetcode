class Solution {
public:
    bool isStrobogrammatic(string num) {
        int start=0;
        int end=num.size()-1;
        while (start<=end){
            if (num[start]==num[end] && (num[start]=='1' || num[start]=='8' || num[start]=='0')){
                start++;
                end--;
                continue;
            }
            
            if ((num[start]=='6' && num[end]=='9') || (num[start]=='9' && num[end]=='6')){
                start++;
                end--;
                continue;
            }
            
            return false;
        }
        
        return true;
    }
};
