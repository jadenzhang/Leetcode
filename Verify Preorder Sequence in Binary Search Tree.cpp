/*class Solution {

public:

    bool verifyPreorder(vector<int>& preorder) {

        int n = preorder.size();

        int a[n];

        int i = 0;

        for(auto p:preorder) a[i++] = p;

        return helper(a, 0, n-1, INT_MIN, INT_MAX);

    }

    bool helper(int preorder[], int s, int e, int lb, int ub){

        if(s>=e) return true;

        int r = preorder[s];

        int i = s;

        while(i<=e && preorder[i]<=r){

            if(preorder[i]<lb || preorder[i]>ub) return false;

            i++;

        }

        return helper(preorder, s+1, i-1, lb, r-1)&&helper(preorder, i, e, r+1, ub);

    }

};*/





// O(1) space
/*class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return check(preorder,0,preorder.size()-1,INT_MIN,INT_MAX);
    }
    
    bool check(vector<int> &preorder, int left, int right, int lb, int rb){
        if (left>=right) return true;
        int root = preorder[left];
        int i = left+1;
        while ((i <= right) && (preorder[i]<root)){
            if (preorder[i]<lb || preorder[i]>rb) return false;
            i++;
        }
        
        return check(preorder,left+1,i-1,lb,root-1)&&check(preorder,i,right,root+1,rb);
        
    }
};*/

// O(n) space
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int lb = INT_MIN;
        stack<int> s;
        
        for (auto node:preorder){
            if (node <= lb) return false;
            
            while ( !s.empty() && node>s.top()){
                lb = s.top();
                s.pop();
            }
            s.push(node);
        }
        
        return true;
    }
};
