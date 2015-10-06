class Solution {
public:
    int countPrimes(int n) {
        vector<bool> table(n,false);
        table[0]=true;
        table[1]=true;
        for (int i=2;i*i<n;i++){
            if (table[i]==false){
                int c=i*i;
                while(c<n){
                    table[c]=true;
                    c+=i;
                }
            }
        }
        int count=0;
        for (int i=0;i<table.size();i++){
            if(!table[i]) count++;
        }
        
        return count;
    }
};
