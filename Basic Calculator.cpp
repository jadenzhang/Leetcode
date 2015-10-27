class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res=0;
        int sign=1;
        for (int i=0;i<s.size();i++){
            if (s[i]<='9' && s[i]>='0'){
                int cur=s[i]-'0';
                while (i+1<s.size() && (s[i+1]<='9' && s[i+1]>='0')){
                    cur=cur*10+(s[i+1]-'0');
                    i++;
                }
                
                res = res + sign*cur;
            }
            else if (s[i]=='+'){
                sign=1;
            }
            else if (s[i]=='-'){
                sign=-1;
            }
            else if (s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if (s[i]==')'){
                sign=st.top();
                st.pop();
                res = st.top()+sign*res;
                st.pop();
            }
        }
        
        return res;
    }
};
