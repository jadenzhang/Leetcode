class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 0;
        stringstream ss(preorder);
        string temp;
        vector<string> node;
        while (getline(ss,temp,',')) node.push_back(temp);
        
        for(int i=0;i<node.size()-1;i++){
            if (node[i]=="#"){
                if (count==0) return false;
                count--;
                
            }
            else count++;
        }
        return (count!=0)? false:node.back()=="#"? true:false;
        
        
    }
};
