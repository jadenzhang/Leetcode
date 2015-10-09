class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length()+t.length()==1) return true;
        if (abs((int)(t.length()-s.length()))>1) return false;
        
        if (s.length() == t.length()){
            int count=0;
            for (int i=0;i<s.length();i++){
                if(s.at(i) != t.at(i)) {
                    count++;
                }
                if (count>1) {
                    return false;
                }
            }
            return count==1;
        }
        else{
            string ss;
            string ls;
            if (s.length() > t.length()){
                ss=t;
                ls=s;
            }
            else{
                ss=s;
                ls=t;
            }
            int i=0,j=0;
            int count=0;
            while (i<ss.length() && j<ls.length()){
                if (ss[i] != ls[j]){
                    count++;
                    j++;
                    if (count>1){ 
                        return false;
                    }
                }
                else{
                    i++;
                    j++;
                }
            }
            return true;
        }
    }
};



