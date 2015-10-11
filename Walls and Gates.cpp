class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size()==0) return;
        queue<pair<int,int>> q;
        int m=rooms.size(), n=rooms[0].size();
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (!rooms[i][j]){
                    q.push({i,j});
                }
            }
        }
        
        for (int d=1;!q.empty();d++){
            for(int k=q.size();k>0;k--){// q.size() may change, so we have to assign it to k frist, and then decrease every time
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                update(rooms,q,m,n,i+1,j,d);
                update(rooms,q,m,n,i-1,j,d);
                update(rooms,q,m,n,i,j+1,d);
                update(rooms,q,m,n,i,j-1,d);
            }
        }
    }
    
    void update(vector<vector<int>> &rooms, queue<pair<int, int>> &q,int m, int n, int i, int j, int d){
        if (i>=0 && j>=0 && i<m && j<n && rooms[i][j]>d ){
            q.push({i,j});
            rooms[i][j]=d;
        }
    }
};
