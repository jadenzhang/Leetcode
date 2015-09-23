class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result;
        for (int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; i--,j--){
            int ai= i>=0? a[i]-'0':0;
            int bj= j>=0? b[j]-'0':0;
            int sum = ai+bj+carry;
            
            carry = sum/2;
            result.insert(result.begin(),sum%2+'0');
        }
        
        if (carry == 1) result.insert(result.begin(),1+'0');
        return result;
    }
};
