class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res,t;
        multiset<int> h;
        int cur = 0, pre = 0;
        for (auto a:buildings){
            t.push_back(make_pair(a[0],-a[2]));
            t.push_back(make_pair(a[1],a[2]));
        }
        sort(t.begin(),t.end());
        h.insert(0);
        
        for (auto a:t){
            if (a.second<0) h.insert(-a.second);
            else h.erase(h.find(a.second));
            cur = *(h.rbegin());
            if (cur != pre){
                res.push_back(make_pair(a.first,cur));
                pre = cur;
            } 
        }
        
        return res;
    }
};
