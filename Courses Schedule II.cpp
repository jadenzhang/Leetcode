class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> in(numCourses,0);
        vector<int> res;
        for (auto a:prerequisites){
            graph[a.second].push_back(a.first);
            in[a.first]++;
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (in[i]==0) {
                q.push(i);
                res.push_back(i);
            }
        }
        
        while (!q.empty()){
            int tem=q.front();
            q.pop();
            for (auto a:graph[tem]){
                in[a]--;
                if (in[a]==0) {
                    q.push(a);
                    res.push_back(a);
                }
            }
        }
        if (res.size()!=numCourses){
            res.clear();
            return res;
        }
        else return res;
    }
};
