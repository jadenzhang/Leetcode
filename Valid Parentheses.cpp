class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto a:s){
            if (a=='('||a=='{'||a=='[') st.push(a);
            else if (a==')'){
                if (st.empty() || st.top()!='(') return false;
                else st.pop();
            }
            else if (a=='}'){
                if (st.empty() || st.top()!='{') return false;
                else st.pop();
            }
            
            else if (a==']'){
                if (st.empty() || st.top()!='[') return false;
                else st.pop();                
            }
        }
        
        return st.empty()? true:false;
    }
};
