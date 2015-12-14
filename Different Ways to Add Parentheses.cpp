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

// Speed up by using cachce

class Solution {
private:
    unordered_map<string,vector<int>> cache;
    int compute(int a, int b, char op){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
        }
    }
    
    string generateKey(int start, int end){
        return to_string(start)+'-'+to_string(end);
    }
    
    vector<int> help(string input,int start, int end) {
        string key = generateKey(start,end);
        if (cache.find(key) != cache.end()) return cache[key];
        int number = 0, i = start;
        for (;i<=end && isdigit(input[i]);i++){
            number = number * 10 + input[i]-'0';
        }
        if (i>end) return {number};
        
        vector<int> left,right,different;
        for (int i=start;i<end;i++){
            if (isdigit(input[i])) continue;
        
            left = help(input,start,i-1);
            right = help(input,i+1,end);
            
            for (auto a:left){
                for (auto b: right){
                    different.push_back(compute(a,b,input[i]));
                }
            }
        }
        
        cache[key] = different;
        return different;
    }
    
public:
    vector<int> diffWaysToCompute(string input){
        return help(input, 0, input.length()-1);
    }
    
};
