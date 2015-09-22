class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, sum = 0;
        vector<int> result(digits.size(),0);
        
        for (int i=digits.size()-1;i>=0;i--){
            sum = digits[i]+carry;
            if (sum>9){
                carry = 1;
                sum -= 10;
            }
            else carry=0;
            result[i] =  sum;
        }
        
        if (carry==1) result.insert(result.begin(),1);
        return result;
    }
};
