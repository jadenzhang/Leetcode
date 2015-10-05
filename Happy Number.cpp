class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> table;
        int sum;
        while(n!=1){
            sum=0;
            while(n>0){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n=sum;
            if(table.find(sum) == table.end()){
                table[sum]=1;
            }
            else break;
            
        }
        
        return n==1;
    }
};
