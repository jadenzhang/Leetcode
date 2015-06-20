class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solutions;
        string result;
        if (n!=0) Machine(solutions,result,0,0,n,0);
        return solutions;
    }
    
    void Machine(vector<string>& solutions, string& result, int LeftNumber,int deep, int n, int RightNumber){
        
        if (deep == 2*n){
            solutions.push_back(result);
            return;
        }
        
        if (LeftNumber < n){
            result.push_back('(');
            Machine(solutions,result,LeftNumber+1,deep+1,n,RightNumber);
            result.pop_back();
        }
        
        if (RightNumber < LeftNumber){
            result.push_back(')');
            Machine(solutions,result,LeftNumber,deep+1,n,RightNumber+1);
            result.pop_back();
        }
    }
};
