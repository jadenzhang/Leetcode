class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 1 || prerequisites.size()==0) return true;
        vector<vector<int>> graph(numCourses,vector<int>(0));
        vector<int> in(numCourses,0);
        
        for (auto a: prerequisites){
            graph[a.second].push_back(a.first);
            in[a.first]++;
        }
        
        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (in[i]==0) q.push(i);
        }
        
        while (!q.empty()){
            int tem=q.front();
            q.pop();
            for (auto a:graph[tem]){
                in[a]--;
                if (in[a]==0) q.push(a);
            }
        }
        
        for (int i=0;i<numCourses;i++){
            if (in[i]==0) continue;
            else return false;
        }
        
        return true;
    }
};
