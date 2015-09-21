class Solution {
public:
    string countAndSay(int n) {
        if (n<1) return "";
        string ret="1";
        char prev = ret[0];
        int count = 0;
        
        for (int i=2;i<=n;i++){
            string tem = "";
            char prev = ret[0];
            int count = 1;
            for (int j=1; j<ret.size();j++)
            {
                if (ret[j]==prev){
                    count++;
                }
                else{
                    tem += to_string(count);
                    count = 1;
                    tem.push_back(prev);
                    prev = ret[j];
                }
            }
            tem +=to_string(count);
            tem.push_back(prev);
            ret = tem;
        }
        
        return ret;
    }
};
