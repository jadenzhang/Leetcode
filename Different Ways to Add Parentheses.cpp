class Solution {
private:
    int compute(int a, int b, char op){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
        }
    }
public:
    vector<int> diffWaysToCompute(string input) {
        int number = 0, i = 0;
        for (;i<input.length() && isdigit(input[i]);i++){
            number = number * 10 + input[i]-'0';
        }
        if (i==input.length()) return {number};
        
        vector<int> left,right,different;
        for (int i=0;i<input.length();i++){
            if (isdigit(input[i])) continue;
        
            left = diffWaysToCompute(input.substr(0,i));
            right = diffWaysToCompute(input.substr(i+1, input.length()-i-1));
            
            for (auto a:left){
                for (auto b: right){
                    different.push_back(compute(a,b,input[i]));
                }
            }
        }
        
        return different;
    }
};
